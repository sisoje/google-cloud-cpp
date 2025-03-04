// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "generator/internal/descriptor_utils.h"
#include "google/cloud/log.h"
#include "google/cloud/testing_util/status_matchers.h"
#include "absl/strings/str_split.h"
#include "generator/testing/printer_mocks.h"
#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/descriptor_database.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/text_format.h>
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace generator_internal {
namespace {

using ::google::cloud::generator_testing::MockGeneratorContext;
using ::google::cloud::generator_testing::MockZeroCopyOutputStream;
using ::google::cloud::testing_util::IsOk;
using ::google::cloud::testing_util::StatusIs;
using ::google::protobuf::DescriptorPool;
using ::google::protobuf::FileDescriptor;
using ::google::protobuf::FileDescriptorProto;
using ::google::protobuf::MethodDescriptor;
using ::testing::_;
using ::testing::AllOf;
using ::testing::Contains;
using ::testing::ElementsAre;
using ::testing::Eq;
using ::testing::Field;
using ::testing::HasSubstr;
using ::testing::Matcher;
using ::testing::Not;
using ::testing::Pair;
using ::testing::Return;
using ::testing::UnorderedElementsAre;

class StringSourceTree : public google::protobuf::compiler::SourceTree {
 public:
  explicit StringSourceTree(std::map<std::string, std::string> files)
      : files_(std::move(files)) {}

  google::protobuf::io::ZeroCopyInputStream* Open(
      std::string const& filename) override {
    auto iter = files_.find(filename);
    return iter == files_.end() ? nullptr
                                : new google::protobuf::io::ArrayInputStream(
                                      iter->second.data(),
                                      static_cast<int>(iter->second.size()));
  }

 private:
  std::map<std::string, std::string> files_;
};

class AbortingErrorCollector : public DescriptorPool::ErrorCollector {
 public:
  AbortingErrorCollector() = default;
  AbortingErrorCollector(AbortingErrorCollector const&) = delete;
  AbortingErrorCollector& operator=(AbortingErrorCollector const&) = delete;

  void AddError(std::string const& filename, std::string const& element_name,
                google::protobuf::Message const*, ErrorLocation,
                std::string const& error_message) override {
    GCP_LOG(FATAL) << "AddError() called unexpectedly: " << filename << " ["
                   << element_name << "]: " << error_message;
  }
};

char const* const kHttpProto =
    "syntax = \"proto3\";\n"
    "package google.api;\n"
    "option cc_enable_arenas = true;\n"
    "message Http {\n"
    "  repeated HttpRule rules = 1;\n"
    "  bool fully_decode_reserved_expansion = 2;\n"
    "}\n"
    "message HttpRule {\n"
    "  string selector = 1;\n"
    "  oneof pattern {\n"
    "    string get = 2;\n"
    "    string put = 3;\n"
    "    string post = 4;\n"
    "    string delete = 5;\n"
    "    string patch = 6;\n"
    "    CustomHttpPattern custom = 8;\n"
    "  }\n"
    "  string body = 7;\n"
    "  string response_body = 12;\n"
    "  repeated HttpRule additional_bindings = 11;\n"
    "}\n"
    "message CustomHttpPattern {\n"
    "  string kind = 1;\n"
    "  string path = 2;\n"
    "}\n";

char const* const kAnnotationsProto =
    "syntax = \"proto3\";\n"
    "package google.api;\n"
    "import \"google/api/http.proto\";\n"
    "import \"google/protobuf/descriptor.proto\";\n"
    "extend google.protobuf.MethodOptions {\n"
    "  // See `HttpRule`.\n"
    "  HttpRule http = 72295728;\n"
    "}\n";

char const* const kFrobberServiceProto =
    "syntax = \"proto3\";\n"
    "package google.cloud.frobber.v1;\n"
    "import \"google/api/annotations.proto\";\n"
    "import \"google/api/http.proto\";\n"
    "// Leading comments about message Bar.\n"
    "message Bar {\n"
    "  int32 number = 1;\n"
    "}\n"
    "// Leading comments about message Empty.\n"
    "message Empty {}\n"
    "// Leading comments about service FrobberService.\n"
    "// $Delimiter escapes$ $\n"
    "service FrobberService {\n"
    "  // Leading comments about rpc Method0.\n"
    "  rpc Method0(Bar) returns (Empty) {\n"
    "    option (google.api.http) = {\n"
    "       delete: \"/v1/{name=projects/*/instances/*/backups/*}\"\n"
    "    };\n"
    "  }\n"
    "}\n";

class CreateServiceVarsTest
    : public testing::TestWithParam<std::pair<std::string, std::string>> {
 public:
  CreateServiceVarsTest()
      : source_tree_(std::map<std::string, std::string>{
            {std::string("google/api/http.proto"), kHttpProto},
            {std::string("google/api/annotations.proto"), kAnnotationsProto},
            {std::string("google/cloud/frobber/v1/frobber.proto"),
             kFrobberServiceProto}}),
        source_tree_db_(&source_tree_),
        merged_db_(&simple_db_, &source_tree_db_),
        pool_(&merged_db_, &collector_) {
    // we need descriptor.proto to be accessible by the pool
    // since our test file imports it
    FileDescriptorProto::descriptor()->file()->CopyTo(&file_proto_);
    simple_db_.Add(file_proto_);
    service_vars_ = {};
  }

 private:
  FileDescriptorProto file_proto_;
  AbortingErrorCollector collector_;
  StringSourceTree source_tree_;
  google::protobuf::SimpleDescriptorDatabase simple_db_;
  google::protobuf::compiler::SourceTreeDescriptorDatabase source_tree_db_;
  google::protobuf::MergedDescriptorDatabase merged_db_;

 protected:
  DescriptorPool pool_;
  VarsDictionary service_vars_;
};

TEST_F(CreateServiceVarsTest, FilesParseSuccessfully) {
  EXPECT_NE(nullptr, pool_.FindFileByName("google/api/http.proto"));
  EXPECT_NE(nullptr, pool_.FindFileByName("google/api/annotations.proto"));
  EXPECT_NE(nullptr,
            pool_.FindFileByName("google/cloud/frobber/v1/frobber.proto"));
}

TEST_F(CreateServiceVarsTest, RetryStatusCodeExpressionNotFound) {
  auto iter = service_vars_.find("retry_status_code_expression");
  EXPECT_TRUE(iter == service_vars_.end());
}

TEST_F(CreateServiceVarsTest, AdditionalGrpcHeaderPathsEmpty) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/cloud/frobber/v1/frobber.proto");
  service_vars_ = CreateServiceVars(
      *service_file_descriptor->service(0),
      {std::make_pair("product_path", "google/cloud/frobber/")});
  auto iter = service_vars_.find("additional_pb_header_paths");
  EXPECT_TRUE(iter != service_vars_.end());
  EXPECT_THAT(iter->second, Eq(""));
}

TEST_P(CreateServiceVarsTest, KeySetCorrectly) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/cloud/frobber/v1/frobber.proto");
  service_vars_ = CreateServiceVars(
      *service_file_descriptor->service(0),
      {std::make_pair("product_path", "google/cloud/frobber/"),
       std::make_pair("additional_proto_files",
                      "google/cloud/add1.proto,google/cloud/add2.proto")});
  auto iter = service_vars_.find(GetParam().first);
  EXPECT_TRUE(iter != service_vars_.end());
  EXPECT_THAT(iter->second, HasSubstr(GetParam().second));
}

INSTANTIATE_TEST_SUITE_P(
    ServiceVars, CreateServiceVarsTest,
    testing::Values(
        std::make_pair("product_options_page", "google-cloud-frobber-options"),
        std::make_pair("additional_pb_header_paths",
                       "google/cloud/add1.pb.h,google/cloud/add2.pb.h"),
        std::make_pair("class_comment_block",
                       "///\n/// Leading comments about service "
                       "FrobberService.\n/// $Delimiter escapes$ $\n///"),
        std::make_pair("client_class_name", "FrobberServiceClient"),
        std::make_pair("client_cc_path",
                       "google/cloud/frobber/"
                       "frobber_client.cc"),
        std::make_pair("client_header_path",
                       "google/cloud/frobber/"
                       "frobber_client.h"),
        std::make_pair("connection_class_name", "FrobberServiceConnection"),
        std::make_pair("connection_cc_path",
                       "google/cloud/frobber/"
                       "frobber_connection.cc"),
        std::make_pair("connection_header_path",
                       "google/cloud/frobber/"
                       "frobber_connection.h"),
        std::make_pair("connection_options_name",
                       "FrobberServiceConnectionOptions"),
        std::make_pair("connection_options_traits_name",
                       "FrobberServiceConnectionOptionsTraits"),
        std::make_pair("grpc_stub_fqn",
                       "google::cloud::frobber::v1::FrobberService"),
        std::make_pair("idempotency_class_name",
                       "FrobberServiceConnectionIdempotencyPolicy"),
        std::make_pair("idempotency_policy_cc_path",
                       "google/cloud/frobber/"
                       "frobber_connection_idempotency_policy.cc"),
        std::make_pair("idempotency_policy_header_path",
                       "google/cloud/frobber/"
                       "frobber_connection_idempotency_policy.h"),
        std::make_pair("limited_error_count_retry_policy_name",
                       "FrobberServiceLimitedErrorCountRetryPolicy"),
        std::make_pair("limited_time_retry_policy_name",
                       "FrobberServiceLimitedTimeRetryPolicy"),
        std::make_pair("logging_class_name", "FrobberServiceLogging"),
        std::make_pair("logging_cc_path",
                       "google/cloud/frobber/internal/"
                       "frobber_logging_decorator.cc"),
        std::make_pair("logging_header_path",
                       "google/cloud/frobber/internal/"
                       "frobber_logging_decorator.h"),
        std::make_pair("metadata_class_name", "FrobberServiceMetadata"),
        std::make_pair("metadata_cc_path",
                       "google/cloud/frobber/internal/"
                       "frobber_metadata_decorator.cc"),
        std::make_pair("metadata_header_path",
                       "google/cloud/frobber/internal/"
                       "frobber_metadata_decorator.h"),
        std::make_pair("mock_connection_class_name",
                       "MockFrobberServiceConnection"),
        std::make_pair("mock_connection_header_path",
                       "google/cloud/frobber/mocks/"
                       "mock_frobber_connection.h"),
        std::make_pair("option_defaults_cc_path",
                       "google/cloud/frobber/internal/"
                       "frobber_option_defaults.cc"),
        std::make_pair("option_defaults_header_path",
                       "google/cloud/frobber/internal/"
                       "frobber_option_defaults.h"),
        std::make_pair("options_header_path",
                       "google/cloud/frobber/frobber_options.h"),
        std::make_pair("product_namespace", "frobber"),
        std::make_pair("product_internal_namespace", "frobber_internal"),
        std::make_pair("proto_file_name",
                       "google/cloud/frobber/v1/frobber.proto"),
        std::make_pair("proto_grpc_header_path",
                       "google/cloud/frobber/v1/frobber.grpc.pb.h"),
        std::make_pair("retry_policy_name", "FrobberServiceRetryPolicy"),
        std::make_pair("retry_traits_name", "FrobberServiceRetryTraits"),
        std::make_pair("retry_traits_header_path",
                       "google/cloud/frobber/internal/frobber_retry_traits.h"),
        std::make_pair("service_endpoint", ""),
        std::make_pair("service_endpoint_env_var",
                       "GOOGLE_CLOUD_CPP_FROBBER_SERVICE_ENDPOINT"),
        std::make_pair("service_name", "FrobberService"),
        std::make_pair("stub_class_name", "FrobberServiceStub"),
        std::make_pair("stub_cc_path",
                       "google/cloud/frobber/internal/frobber_stub.cc"),
        std::make_pair("stub_header_path",
                       "google/cloud/frobber/internal/frobber_stub.h"),
        std::make_pair("stub_factory_cc_path",
                       "google/cloud/frobber/internal/frobber_stub_factory.cc"),
        std::make_pair("stub_factory_header_path",
                       "google/cloud/frobber/internal/frobber_stub_factory.h")),
    [](testing::TestParamInfo<CreateServiceVarsTest::ParamType> const& info) {
      return std::get<0>(info.param);
    });

char const* const kClientProto =
    "syntax = \"proto3\";\n"
    "package google.api;\n"
    "import \"google/protobuf/descriptor.proto\";\n"
    "extend google.protobuf.MethodOptions {\n"
    "  repeated string method_signature = 1051;\n"
    "}\n"
    "extend google.protobuf.ServiceOptions {\n"
    "  string default_host = 1049;\n"
    "  string oauth_scopes = 1050;\n"
    "}\n";

char const* const kLongrunningOperationsProto =
    "syntax = \"proto3\";\n"
    "package google.longrunning;\n"
    "import \"google/protobuf/descriptor.proto\";\n"
    "extend google.protobuf.MethodOptions {\n"
    "  google.longrunning.OperationInfo operation_info = 1049;\n"
    "}\n"
    "message Operation {\n"
    "  string blah = 1;\n"
    "}\n"
    "message OperationInfo {\n"
    "  string response_type = 1;\n"
    "  string metadata_type = 2;\n"
    "}\n";

char const* const kSourceLocationTestInput =
    "syntax = \"proto3\";\n"
    "import \"google/api/annotations.proto\";\n"
    "message A {\n"
    "  int32 a = 1;\n"
    "}\n"
    "message B {\n"
    "  int32 b = 1;\n"
    "}\n"
    "service S {\n"
    "  rpc Method(A) returns (B) {\n"
    "    option (google.api.http) = {\n"
    "      get: \"/v1/{parent=projects/*/instances/*}/databases\"\n"
    "    };\n"
    "  }\n"
    "  rpc OtherMethod(A) returns (A) {\n"
    "    option (google.api.http) = {\n"
    "      get: \"/v1/{parent=projects/*/instances/*}/databases\"\n"
    "    };\n"
    "  }\n"
    "}\n";

char const* const kServiceProto =
    "syntax = \"proto3\";\n"
    "package google.protobuf;\n"
    "import \"google/api/annotations.proto\";\n"
    "import \"google/api/client.proto\";\n"
    "import \"google/api/http.proto\";\n"
    "import \"google/longrunning/operation.proto\";\n"
    "// Leading comments about message Foo.\n"
    "message Foo {\n"
    "  // name field$ comment.\n"
    "  string name = 1;\n"
    "  // labels $field comment.\n"
    "  map<string, string> labels = 2;\n"
    "  string not_used_anymore = 3 [deprecated = true];\n"
    "}\n"
    "// Leading comments about message Bar.\n"
    "message Bar {\n"
    "  enum SwallowType {\n"
    "    I_DONT_KNOW = 0;\n"
    "    AFRICAN = 1;\n"
    "    EUROPEAN = 2;\n"
    "  }\n"
    "  int32 number = 1;\n"
    "  string name = 2;\n"
    "  Foo widget = 3;\n"
    "  bool toggle = 4;\n"
    "  string title = 5;\n"
    "  repeated SwallowType swallow_types = 6;\n"
    "  string parent = 7;\n"
    "}\n"
    "// Leading comments about message Empty.\n"
    "message Empty {}\n"
    "// Leading comments about message PaginatedInput.\n"
    "message PaginatedInput {\n"
    "  int32 page_size = 1;\n"
    "  string page_token = 2;\n"
    "  string name = 3;\n"
    "}\n"
    "// Leading comments about message PaginatedOutput.\n"
    "message PaginatedOutput {\n"
    "  string next_page_token = 1;\n"
    "  repeated Bar repeated_field = 2;\n"
    "}\n"
    "message Namespace {\n"
    "  string name = 1;\n"
    "}\n"
    "message NamespaceRequest {\n"
    "  // namespace $field comment.\n"
    "  Namespace namespace = 1;\n"
    "}\n"
    "// Leading comments about service Service.\n"
    "service Service {\n"
    "  // Leading comments about rpc Method0$.\n"
    "  rpc Method0(Bar) returns (Empty) {\n"
    "  }\n"
    "  // Leading comments about rpc Method1.\n"
    "  rpc Method1(Bar) returns (Bar) {\n"
    "    option (google.api.http) = {\n"
    "       delete: \"/v1/{name=projects/*/instances/*/backups/*}\"\n"
    "    };\n"
    "  }\n"
    "  // Leading comments about rpc Method2.\n"
    "  rpc Method2(Bar) returns (google.longrunning.Operation) {\n"
    "    option (google.api.http) = {\n"
    "       patch: \"/v1/{parent=projects/*/instances/*}/databases\"\n"
    "       body: \"*\"\n"
    "    };\n"
    "    option (google.longrunning.operation_info) = {\n"
    "      response_type: \"google.protobuf.Bar\"\n"
    "      metadata_type: \"google.protobuf.Method2Metadata\"\n"
    "    };\n"
    "  }\n"
    "  // Leading comments about rpc Method3.\n"
    "  rpc Method3(Bar) returns (google.longrunning.Operation) {\n"
    "    option (google.api.http) = {\n"
    "       put: \"/v1/{parent=projects/*/instances/*}/databases\"\n"
    "    };\n"
    "    option (google.longrunning.operation_info) = {\n"
    "      response_type: \"google.protobuf.Empty\"\n"
    "      metadata_type: \"google.protobuf.Struct\"\n"
    "    };\n"
    "  }\n"
    "  // Leading comments about rpc Method4.\n"
    "  rpc Method4(PaginatedInput) returns (PaginatedOutput) {\n"
    "    option (google.api.http) = {\n"
    "       delete: \"/v1/{name=projects/*/instances/*/backups/*}\"\n"
    "    };\n"
    "  }\n"
    "  // Leading comments about rpc Method5.\n"
    "  rpc Method5(Bar) returns (Empty) {\n"
    "    option (google.api.http) = {\n"
    "       post: \"/v1/{parent=projects/*/instances/*}/databases\"\n"
    "       body: \"*\"\n"
    "    };\n"
    "    option (google.api.method_signature) = \"name\";\n"
    "    option (google.api.method_signature) = \"number, widget\";\n"
    "    option (google.api.method_signature) = \"toggle\";\n"
    "    option (google.api.method_signature) = \"name,title\";\n"
    "    option (google.api.method_signature) = \"name,swallow_types\";\n"
    "    option (google.api.method_signature) = \"\";\n"
    "  }\n"
    "  // Leading comments about rpc $Method6.\n"
    "  rpc Method6(Foo) returns (Empty) {\n"
    "    option (google.api.http) = {\n"
    "       get: \"/v1/{name=projects/*/instances/*/databases/*}\"\n"
    "    };\n"
    "    option (google.api.method_signature) = \"name,not_used_anymore\";\n"
    "    option (google.api.method_signature) = \"labels\";\n"
    "    option (google.api.method_signature) = \"not_used_anymore,labels\";\n"
    "    option (google.api.method_signature) = \"name,labels\";\n"
    "  }\n"
    "  // Leading comments about rpc Method7.\n"
    "  rpc Method7(Bar) returns (google.longrunning.Operation) {\n"
    "    option (google.api.http) = {\n"
    "       patch: \"/v1/{parent=projects/*/instances/*}/databases\"\n"
    "       body: \"*\"\n"
    "    };\n"
    "    option (google.longrunning.operation_info) = {\n"
    "      response_type: \"Bar\"\n"
    "      metadata_type: \"google.protobuf.Method2Metadata\"\n"
    "    };\n"
    "  }\n"
    "  // Leading comments about rpc Method8.\n"
    "  rpc Method8(NamespaceRequest) returns (Empty) {\n"
    "    option (google.api.http) = {\n"
    "      patch: "
    "\"/v1/{namespace.name=projects/*/locations/*/namespaces/*}\"\n"
    "      body: \"namespace\"\n"
    "    };\n"
    "    option (google.api.method_signature) = \"namespace\";\n"
    "  }\n"
    "  // Leading comments about rpc Method9.\n"
    "  rpc Method9(PaginatedInput) returns (PaginatedOutput) {\n"
    "    option (google.api.http) = {\n"
    "       get: \"/v1/foo\"\n"
    "       body: \"*\"\n"
    "    };\n"
    "  }\n"
    "  // Leading comments about rpc Method10.\n"
    "  rpc Method10(Bar) returns (Empty) {\n"
    "    option (google.api.method_signature) = \"name\";\n"
    "    option (google.api.method_signature) = \"parent\";\n"
    "    option (google.api.method_signature) = \"name,parent,number\";\n"
    "    option (google.api.method_signature) = \"name,title,number\";\n"
    "  }\n"
    "}\n";

struct MethodVarsTestValues {
  MethodVarsTestValues(std::string m, std::string k, std::string v)
      : method(std::move(m)),
        vars_key(std::move(k)),
        expected_value(std::move(v)) {}
  std::string method;
  std::string vars_key;
  std::string expected_value;
};

class CreateMethodVarsTest
    : public testing::TestWithParam<MethodVarsTestValues> {
 public:
  CreateMethodVarsTest()
      : source_tree_(std::map<std::string, std::string>{
            {std::string("google/api/client.proto"), kClientProto},
            {std::string("google/api/http.proto"), kHttpProto},
            {std::string("google/api/annotations.proto"), kAnnotationsProto},
            {std::string("google/longrunning/operation.proto"),
             kLongrunningOperationsProto},
            {std::string("test/test.proto"), kSourceLocationTestInput},
            {std::string("google/foo/v1/service.proto"), kServiceProto}}),
        source_tree_db_(&source_tree_),
        merged_db_(&simple_db_, &source_tree_db_),
        pool_(&merged_db_, &collector_) {
    // we need descriptor.proto to be accessible by the pool
    // since our test file imports it
    FileDescriptorProto::descriptor()->file()->CopyTo(&file_proto_);
    simple_db_.Add(file_proto_);
    service_vars_ = {};
  }

 private:
  FileDescriptorProto file_proto_;
  AbortingErrorCollector collector_;
  StringSourceTree source_tree_;
  google::protobuf::SimpleDescriptorDatabase simple_db_;
  google::protobuf::compiler::SourceTreeDescriptorDatabase source_tree_db_;
  google::protobuf::MergedDescriptorDatabase merged_db_;

 protected:
  DescriptorPool pool_;
  std::map<std::string, VarsDictionary> vars_;
  VarsDictionary service_vars_;
};

TEST_F(CreateMethodVarsTest, FilesParseSuccessfully) {
  EXPECT_NE(nullptr, pool_.FindFileByName("google/api/client.proto"));
  EXPECT_NE(nullptr, pool_.FindFileByName("google/api/http.proto"));
  EXPECT_NE(nullptr, pool_.FindFileByName("google/api/annotations.proto"));
  EXPECT_NE(nullptr,
            pool_.FindFileByName("google/longrunning/operation.proto"));
  EXPECT_NE(nullptr, pool_.FindFileByName("test/test.proto"));
  EXPECT_NE(nullptr, pool_.FindFileByName("google/foo/v1/service.proto"));
}

TEST_F(CreateMethodVarsTest, FormatMethodCommentsProtobufRequest) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/foo/v1/service.proto");
  EXPECT_THAT(FormatMethodCommentsProtobufRequest(
                  *service_file_descriptor->service(0)->method(0)),
              HasSubstr(R"""(  ///
  /// Leading comments about rpc Method0$$.
  ///
  /// @param request @googleapis_link{google::protobuf::Bar,google/foo/v1/service.proto#L16}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
)"""));
}

TEST_F(CreateMethodVarsTest, FormatMethodCommentsMethodSignature) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/foo/v1/service.proto");
  EXPECT_THAT(FormatMethodCommentsMethodSignature(
                  *service_file_descriptor->service(0)->method(6), "labels"),
              HasSubstr(R"""(  ///
  /// Leading comments about rpc $$Method6.
  ///
  /// @param labels  labels $$field comment.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
)"""));
  EXPECT_THAT(
      FormatMethodCommentsMethodSignature(
          *service_file_descriptor->service(0)->method(6), "name,labels"),
      HasSubstr(R"""(  ///
  /// Leading comments about rpc $$Method6.
  ///
  /// @param name  name field$$ comment.
  /// @param labels  labels $$field comment.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
)"""));
}

TEST_F(CreateMethodVarsTest, SkipMethodsWithDeprecatedFields) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/foo/v1/service.proto");
  vars_ = CreateMethodVars(*service_file_descriptor->service(0), service_vars_);
  auto method_vars = vars_.find("google.protobuf.Service.Method6");
  ASSERT_NE(method_vars, vars_.end());
  EXPECT_THAT(method_vars->second, Not(Contains(Pair("method_signature0", _))));
  EXPECT_THAT(method_vars->second, Contains(Pair("method_signature1", _)));
  EXPECT_THAT(method_vars->second, Not(Contains(Pair("method_signature2", _))));
  EXPECT_THAT(method_vars->second, Contains(Pair("method_signature3", _)));
}

TEST_F(CreateMethodVarsTest, SkipMethodOverloadsWithDuplicateSignatures) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/foo/v1/service.proto");
  vars_ = CreateMethodVars(*service_file_descriptor->service(0), service_vars_);
  auto method_vars = vars_.find("google.protobuf.Service.Method10");
  ASSERT_NE(method_vars, vars_.end());
  EXPECT_THAT(method_vars->second, Contains(Pair("method_signature0", _)));
  EXPECT_THAT(method_vars->second, Not(Contains(Pair("method_signature1", _))));
  EXPECT_THAT(method_vars->second, Contains(Pair("method_signature2", _)));
  EXPECT_THAT(method_vars->second, Not(Contains(Pair("method_signature3", _))));
}

TEST_F(CreateMethodVarsTest, ParseHttpExtensionWithPrefixAndSuffix) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/foo/v1/service.proto");
  MethodDescriptor const* method =
      service_file_descriptor->service(0)->method(5);
  auto info = ParseHttpExtension(*method);
  ASSERT_TRUE(absl::holds_alternative<HttpExtensionInfo>(info));
  auto extension_info = absl::get<HttpExtensionInfo>(info);
  EXPECT_THAT(extension_info.url_path,
              Eq("/v1/{parent=projects/*/instances/*}/databases"));
  EXPECT_THAT(extension_info.request_field_name, Eq("parent"));
  EXPECT_THAT(extension_info.url_substitution, Eq("projects/*/instances/*"));
  EXPECT_THAT(extension_info.body, Eq("*"));
  EXPECT_THAT(extension_info.http_verb, Eq("Post"));
  EXPECT_THAT(extension_info.path_prefix, Eq("/v1/"));
  EXPECT_THAT(extension_info.path_suffix, Eq("/databases"));
}

TEST_F(CreateMethodVarsTest, ParseHttpExtensionWithOnlyPrefix) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/foo/v1/service.proto");
  MethodDescriptor const* method =
      service_file_descriptor->service(0)->method(1);
  auto info = ParseHttpExtension(*method);
  ASSERT_TRUE(absl::holds_alternative<HttpExtensionInfo>(info));
  auto extension_info = absl::get<HttpExtensionInfo>(info);
  EXPECT_THAT(extension_info.url_path,
              Eq("/v1/{name=projects/*/instances/*/backups/*}"));
  EXPECT_THAT(extension_info.request_field_name, Eq("name"));
  EXPECT_THAT(extension_info.url_substitution,
              Eq("projects/*/instances/*/backups/*"));
  EXPECT_THAT(extension_info.body, Eq(""));
  EXPECT_THAT(extension_info.http_verb, Eq("Delete"));
  EXPECT_THAT(extension_info.path_prefix, Eq("/v1/"));
  EXPECT_THAT(extension_info.path_suffix, Eq(""));
}

TEST_F(CreateMethodVarsTest, ParseHttpExtensionSimpleInfo) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/foo/v1/service.proto");
  MethodDescriptor const* method =
      service_file_descriptor->service(0)->method(9);
  auto info = ParseHttpExtension(*method);
  ASSERT_TRUE(absl::holds_alternative<HttpSimpleInfo>(info));
  auto extension_info = absl::get<HttpSimpleInfo>(info);
  EXPECT_THAT(extension_info.url_path, Eq("/v1/foo"));
  EXPECT_THAT(extension_info.body, Eq("*"));
  EXPECT_THAT(extension_info.http_verb, Eq("Get"));
}

TEST_P(CreateMethodVarsTest, KeySetCorrectly) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/foo/v1/service.proto");
  vars_ = CreateMethodVars(*service_file_descriptor->service(0), service_vars_);
  auto method_iter = vars_.find(GetParam().method);
  ASSERT_TRUE(method_iter != vars_.end());
  EXPECT_THAT(method_iter->second,
              Contains(Pair(GetParam().vars_key, GetParam().expected_value)));
}

INSTANTIATE_TEST_SUITE_P(
    MethodVars, CreateMethodVarsTest,
    testing::Values(
        // Method0
        MethodVarsTestValues("google.protobuf.Service.Method0", "method_name",
                             "Method0"),
        MethodVarsTestValues("google.protobuf.Service.Method0",
                             "method_name_snake", "method0"),
        MethodVarsTestValues("google.protobuf.Service.Method0", "request_type",
                             "google::protobuf::Bar"),
        MethodVarsTestValues("google.protobuf.Service.Method0",
                             "response_message_type", "google.protobuf.Empty"),
        MethodVarsTestValues("google.protobuf.Service.Method0", "response_type",
                             "google::protobuf::Empty"),
        MethodVarsTestValues("google.protobuf.Service.Method0",
                             "default_idempotency", "kNonIdempotent"),
        MethodVarsTestValues("google.protobuf.Service.Method0",
                             "method_return_doxygen_link",
                             "@googleapis_link{google::protobuf::Empty,google/"
                             "foo/v1/service.proto#L31}"),
        MethodVarsTestValues("google.protobuf.Service.Method0",
                             "method_http_query_parameters",
                             "google.protobuf.Service.Method0"),
        // Method1
        MethodVarsTestValues("google.protobuf.Service.Method1", "method_name",
                             "Method1"),
        MethodVarsTestValues("google.protobuf.Service.Method1",
                             "method_name_snake", "method1"),
        MethodVarsTestValues("google.protobuf.Service.Method1", "request_type",
                             "google::protobuf::Bar"),
        MethodVarsTestValues("google.protobuf.Service.Method1", "response_type",
                             "google::protobuf::Bar"),
        MethodVarsTestValues("google.protobuf.Service.Method1",
                             "method_return_doxygen_link",
                             "@googleapis_link{google::protobuf::Bar,google/"
                             "foo/v1/service.proto#L16}"),
        MethodVarsTestValues("google.protobuf.Service.Method1",
                             "method_http_query_parameters", ""),
        // Method2
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "longrunning_metadata_type",
                             "google::protobuf::Method2Metadata"),
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "longrunning_response_type",
                             "google::protobuf::Bar"),
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "longrunning_deduced_response_message_type",
                             "google.protobuf.Bar"),
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "longrunning_deduced_response_type",
                             "google::protobuf::Bar"),
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "method_request_param_key", "parent"),
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "method_request_param_value", "parent()"),
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "method_request_url_path",
                             "/v1/{parent=projects/*/instances/*}/databases"),
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "method_request_url_substitution",
                             "projects/*/instances/*"),
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "default_idempotency", "kNonIdempotent"),
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "method_longrunning_deduced_return_doxygen_link",
                             "@googleapis_link{google::protobuf::Bar,google/"
                             "foo/v1/service.proto#L16}"),
        MethodVarsTestValues("google.protobuf.Service.Method2",
                             "method_http_query_parameters", ""),
        // Method3
        MethodVarsTestValues("google.protobuf.Service.Method3",
                             "longrunning_metadata_type",
                             "google::protobuf::Struct"),
        MethodVarsTestValues("google.protobuf.Service.Method3",
                             "longrunning_response_type",
                             "google::protobuf::Empty"),
        MethodVarsTestValues("google.protobuf.Service.Method3",
                             "longrunning_deduced_response_type",
                             "google::protobuf::Struct"),
        MethodVarsTestValues("google.protobuf.Service.Method3",
                             "method_request_param_key", "parent"),
        MethodVarsTestValues("google.protobuf.Service.Method3",
                             "method_request_param_value", "parent()"),
        MethodVarsTestValues("google.protobuf.Service.Method3",
                             "method_request_url_path",
                             "/v1/{parent=projects/*/instances/*}/databases"),
        MethodVarsTestValues("google.protobuf.Service.Method3",
                             "method_request_url_substitution",
                             "projects/*/instances/*"),
        MethodVarsTestValues("google.protobuf.Service.Method3",
                             "default_idempotency", "kIdempotent"),
        MethodVarsTestValues("google.protobuf.Service.Method3",
                             "method_longrunning_deduced_return_doxygen_link",
                             "google::protobuf::Struct"),
        // Method4
        MethodVarsTestValues("google.protobuf.Service.Method4",
                             "range_output_field_name", "repeated_field"),
        MethodVarsTestValues("google.protobuf.Service.Method4",
                             "range_output_type", "google::protobuf::Bar"),
        MethodVarsTestValues("google.protobuf.Service.Method4",
                             "method_request_param_key", "name"),
        MethodVarsTestValues("google.protobuf.Service.Method4",
                             "method_request_param_value", "name()"),
        MethodVarsTestValues("google.protobuf.Service.Method4",
                             "method_request_url_path",
                             "/v1/{name=projects/*/instances/*/backups/*}"),
        MethodVarsTestValues("google.protobuf.Service.Method4",
                             "method_request_url_substitution",
                             "projects/*/instances/*/backups/*"),
        MethodVarsTestValues("google.protobuf.Service.Method4",
                             "default_idempotency", "kNonIdempotent"),
        // Method5
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_signature0", "std::string const& name, "),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_signature1",
                             "std::int32_t number, "
                             "google::protobuf::Foo const& widget, "),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_signature2", "bool toggle, "),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_signature3",
                             "std::string const& name, "
                             "std::string const& title, "),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_signature4",
                             "std::string const& name, "
                             "std::vector<google::protobuf::Bar::SwallowType>"
                             " const& swallow_types, "),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_signature5", ""),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_request_setters0",
                             "  request.set_name(name);\n"),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_request_setters1",
                             "  request.set_number(number);\n"
                             "  *request.mutable_widget() = widget;\n"),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_request_param_key", "parent"),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_request_param_value", "parent()"),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_request_url_path",
                             "/v1/{parent=projects/*/instances/*}/databases"),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_request_url_substitution",
                             "projects/*/instances/*"),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "method_request_body", "*"),
        MethodVarsTestValues("google.protobuf.Service.Method5",
                             "default_idempotency", "kNonIdempotent"),
        MethodVarsTestValues(
            "google.protobuf.Service.Method5", "method_rest_path",
            "absl::StrCat(\"/v1/\", request.parent(), \"/databases\")"),
        // Method6
        MethodVarsTestValues("google.protobuf.Service.Method6",
                             "method_request_param_key", "name"),
        MethodVarsTestValues("google.protobuf.Service.Method6",
                             "method_request_param_value", "name()"),
        MethodVarsTestValues("google.protobuf.Service.Method6",
                             "method_request_url_path",
                             "/v1/{name=projects/*/instances/*/databases/*}"),
        MethodVarsTestValues("google.protobuf.Service.Method6",
                             "method_request_url_substitution",
                             "projects/*/instances/*/databases/*"),
        MethodVarsTestValues("google.protobuf.Service.Method6",
                             "default_idempotency", "kIdempotent"),
        MethodVarsTestValues(
            "google.protobuf.Service.Method6", "method_signature1",
            "std::map<std::string, std::string> const& labels, "),
        MethodVarsTestValues(
            "google.protobuf.Service.Method6", "method_request_setters1",
            "  *request.mutable_labels() = {labels.begin(), labels.end()};\n"),
        MethodVarsTestValues("google.protobuf.Service.Method6",
                             "method_http_query_parameters",
                             R"""(,
      {std::make_pair("not_used_anymore", request.not_used_anymore())})"""),
        // Method7
        MethodVarsTestValues("google.protobuf.Service.Method7",
                             "longrunning_metadata_type",
                             "google::protobuf::Method2Metadata"),
        MethodVarsTestValues("google.protobuf.Service.Method7",
                             "longrunning_response_type",
                             "google::protobuf::Bar"),
        MethodVarsTestValues("google.protobuf.Service.Method7",
                             "longrunning_deduced_response_message_type",
                             "google.protobuf.Bar"),
        MethodVarsTestValues("google.protobuf.Service.Method7",
                             "longrunning_deduced_response_type",
                             "google::protobuf::Bar"),
        MethodVarsTestValues("google.protobuf.Service.Method7",
                             "method_longrunning_deduced_return_doxygen_link",
                             "@googleapis_link{google::protobuf::Bar,google/"
                             "foo/v1/service.proto#L16}"),
        // Method8
        MethodVarsTestValues("google.protobuf.Service.Method8",
                             "method_signature0",
                             "google::protobuf::Namespace const& namespace_, "),
        MethodVarsTestValues("google.protobuf.Service.Method8",
                             "method_request_setters0",
                             "  *request.mutable_namespace_() = namespace_;\n"),
        MethodVarsTestValues("google.protobuf.Service.Method8",
                             "method_request_param_key", "namespace.name"),
        MethodVarsTestValues("google.protobuf.Service.Method8",
                             "method_request_param_value",
                             "namespace_().name()"),
        MethodVarsTestValues(
            "google.protobuf.Service.Method8", "method_rest_path",
            "absl::StrCat(\"/v1/\", request.namespace_().name(), \"\")"),
        // Method9
        MethodVarsTestValues("google.protobuf.Service.Method9",
                             "method_http_query_parameters",
                             R"""(,
      {std::make_pair("page_size", std::to_string(request.page_size())),
       std::make_pair("page_token", request.page_token()),
       std::make_pair("name", request.name())})""")),
    [](testing::TestParamInfo<CreateMethodVarsTest::ParamType> const& info) {
      std::vector<std::string> pieces = absl::StrSplit(info.param.method, '.');
      return pieces.back() + "_" + info.param.vars_key;
    });

class PrintMethodTest : public ::testing::Test {
 protected:
  void SetUp() override {
    /// @cond
    auto constexpr kServiceText = R"pb(
      name: "google/foo/v1/service.proto"
      package: "google.protobuf"
      message_type {
        name: "Bar"
        field { name: "number" number: 1 type: TYPE_INT32 }
        field { name: "name" number: 2 type: TYPE_STRING }
        field {
          name: "widget"
          number: 3
          type: TYPE_MESSAGE
          type_name: "google.protobuf.Bar"
        }
      }
      message_type { name: "Empty" }
      service {
        name: "Service"
        method {
          name: "Method0"
          input_type: "google.protobuf.Bar"
          output_type: "google.protobuf.Empty"
        }
        method {
          name: "Method1"
          input_type: "google.protobuf.Bar"
          output_type: "google.protobuf.Bar"
        }
      }
    )pb";
    /// @endcond
    ASSERT_TRUE(google::protobuf::TextFormat::ParseFromString(kServiceText,
                                                              &service_file_));
  }

  google::protobuf::FileDescriptorProto service_file_;
};

TEST_F(PrintMethodTest, NoMatchingPatterns) {
  DescriptorPool pool;
  FileDescriptor const* service_file_descriptor = pool.BuildFile(service_file_);

  auto generator_context = absl::make_unique<MockGeneratorContext>();
  auto output = absl::make_unique<MockZeroCopyOutputStream>();
  EXPECT_CALL(*generator_context, Open("foo"))
      .WillOnce(Return(output.release()));
  Printer printer(generator_context.get(), "foo");

  auto result = PrintMethod(*service_file_descriptor->service(0)->method(0),
                            printer, {}, {}, "some_file", 42);
  EXPECT_THAT(result, StatusIs(Not(StatusCode::kOk),
                               HasSubstr("no matching patterns")));
}

TEST_F(PrintMethodTest, MoreThanOneMatchingPattern) {
  DescriptorPool pool;
  FileDescriptor const* service_file_descriptor = pool.BuildFile(service_file_);

  auto generator_context = absl::make_unique<MockGeneratorContext>();
  auto output = absl::make_unique<MockZeroCopyOutputStream>();
  EXPECT_CALL(*generator_context, Open("foo"))
      .WillOnce(Return(output.release()));
  Printer printer(generator_context.get(), "foo");

  auto always_matches = [](google::protobuf::MethodDescriptor const&) {
    return true;
  };

  std::vector<MethodPattern> patterns = {
      MethodPattern({{"always matches"}}, always_matches),
      MethodPattern({{"also always matches"}}, always_matches)};

  auto result = PrintMethod(*service_file_descriptor->service(0)->method(0),
                            printer, {}, patterns, "some_file", 42);
  EXPECT_THAT(result, StatusIs(Not(StatusCode::kOk),
                               HasSubstr("more than one pattern")));
}

TEST_F(PrintMethodTest, ExactlyOnePattern) {
  DescriptorPool pool;
  FileDescriptor const* service_file_descriptor = pool.BuildFile(service_file_);

  auto generator_context = absl::make_unique<MockGeneratorContext>();
  auto output = absl::make_unique<MockZeroCopyOutputStream>();
  EXPECT_CALL(*output, Next);
  EXPECT_CALL(*generator_context, Open("foo"))
      .WillOnce(Return(output.release()));
  Printer printer(generator_context.get(), "foo");

  auto always_matches = [](google::protobuf::MethodDescriptor const&) {
    return true;
  };
  auto never_matches = [](google::protobuf::MethodDescriptor const&) {
    return false;
  };

  std::vector<MethodPattern> patterns = {
      MethodPattern({{"matches"}}, always_matches),
      MethodPattern({{"does not match"}}, never_matches)};

  auto result = PrintMethod(*service_file_descriptor->service(0)->method(0),
                            printer, {}, patterns, "some_file", 42);
  EXPECT_THAT(result, IsOk());
}

// We factor out the protobuf mumbo jumbo to keep the tests concise and
// self-contained. The protobuf objects must be in scope for the duration of a
// test. To achieve this, we pass in a `test` lambda which is invoked in this
// method.
void RunRoutingTest(std::string const& service_proto,
                    std::function<void(FileDescriptor const*)> const& test) {
  auto constexpr kServiceBoilerPlate = R"""(
syntax = "proto3";
package google.protobuf;
import "google/api/routing.proto";
)""";

  auto constexpr kRoutingProto = R"""(
syntax = "proto3";
package google.api;
import "google/protobuf/descriptor.proto";

extend google.protobuf.MethodOptions {
  google.api.RoutingRule routing = 72295729;
}
message RoutingRule {
  repeated RoutingParameter routing_parameters = 2;
}
message RoutingParameter {
  string field = 1;
  string path_template = 2;
}
)""";

  StringSourceTree source_tree(std::map<std::string, std::string>{
      {"google/api/routing.proto", kRoutingProto},
      {"google/cloud/foo/service.proto", kServiceBoilerPlate + service_proto}});
  google::protobuf::compiler::SourceTreeDescriptorDatabase source_tree_db(
      &source_tree);
  google::protobuf::SimpleDescriptorDatabase simple_db;
  FileDescriptorProto file_proto;
  // we need descriptor.proto to be accessible by the pool
  // since our test file imports it
  FileDescriptorProto::descriptor()->file()->CopyTo(&file_proto);
  simple_db.Add(file_proto);
  google::protobuf::MergedDescriptorDatabase merged_db(&simple_db,
                                                       &source_tree_db);
  AbortingErrorCollector collector;
  DescriptorPool pool(&merged_db, &collector);

  // Run the test
  test(pool.FindFileByName("google/cloud/foo/service.proto"));
}

Matcher<RoutingParameter const&> RP(std::string const& field_name,
                                    std::string const& pattern) {
  return AllOf(Field(&RoutingParameter::field_name, field_name),
               Field(&RoutingParameter::pattern, pattern));
}

TEST(ParseExplicitRoutingHeaderTest, NoRouting) {
  auto constexpr kProto = R"""(
message Foo {
  string foo = 1;
  string bar = 2;
}

service Service0 {
  rpc Method0(Foo) returns (Foo) {}
}
)""";

  RunRoutingTest(kProto, [](FileDescriptor const* fd) {
    auto const& method = *fd->service(0)->method(0);
    auto info = ParseExplicitRoutingHeader(method);
    EXPECT_THAT(info, UnorderedElementsAre());
  });
}

TEST(ParseExplicitRoutingHeaderTest, Regex) {
  auto constexpr kProto = R"""(
message Foo {
  string foo = 1;
  string bar = 2;
}

service Service0 {
  rpc Method0(Foo) returns (Foo) {
    option (google.api.routing) = {
      routing_parameters {
        field: "foo"
        path_template: "projects/*/{routing_key=instances/*}/**"
      }
    };
  }
}
)""";

  RunRoutingTest(kProto, [](FileDescriptor const* fd) {
    auto const& method = *fd->service(0)->method(0);
    auto info = ParseExplicitRoutingHeader(method);
    EXPECT_THAT(
        info,
        UnorderedElementsAre(Pair(
            "routing_key",
            ElementsAre(RP("foo", "projects/[^/]+/(instances/[^/]+)/.*")))));
  });
}

TEST(ParseExplicitRoutingHeaderTest, NoPathTemplate) {
  auto constexpr kProto = R"""(
message Foo {
  string foo = 1;
  string bar = 2;
}

service Service0 {
  rpc Method0(Foo) returns (Foo) {
    option (google.api.routing) = {
      routing_parameters {
        field: "foo"
      }
    };
  }
}
)""";

  RunRoutingTest(kProto, [](FileDescriptor const* fd) {
    auto const& method = *fd->service(0)->method(0);
    auto info = ParseExplicitRoutingHeader(method);
    // When the path template is not present, we should use the field name as
    // the routing parameter key, and our regex should have one capture group
    // that matches all.
    EXPECT_THAT(info, UnorderedElementsAre(
                          Pair("foo", ElementsAre(RP("foo", "(.*)")))));
  });
}

TEST(ParseExplicitRoutingHeaderTest, OrderReversed) {
  auto constexpr kProto = R"""(
message Foo {
  string foo = 1;
  string bar = 2;
}

service Service0 {
  rpc Method0(Foo) returns (Foo) {
    option (google.api.routing) = {
      routing_parameters {
        field: "foo"
        path_template: "{routing_key=foo-path-1}"
      }
      routing_parameters {
        field: "bar"
        path_template: "{routing_key=bar-path-2}"
      }
      routing_parameters {
        field: "foo"
        path_template: "{routing_key=foo-path-3}"
      }
    };
  }
}
)""";

  RunRoutingTest(kProto, [](FileDescriptor const* fd) {
    auto const& method = *fd->service(0)->method(0);
    auto info = ParseExplicitRoutingHeader(method);
    EXPECT_THAT(
        info, UnorderedElementsAre(
                  Pair("routing_key", ElementsAre(RP("foo", "(foo-path-3)"),
                                                  RP("bar", "(bar-path-2)"),
                                                  RP("foo", "(foo-path-1)")))));
  });
}

TEST(ParseExplicitRoutingHeaderTest, GroupsByRoutingKey) {
  auto constexpr kProto = R"""(
message Foo {
  string foo = 1;
  string bar = 2;
}

service Service0 {
  rpc Method0(Foo) returns (Foo) {
    option (google.api.routing) = {
      routing_parameters {
        field: "foo"
        path_template: "{routing_key1=foo-path-1}"
      }
      routing_parameters {
        field: "foo"
        path_template: "{routing_key2=foo-path-2}"
      }
      routing_parameters {
        field: "bar"
        path_template: "{routing_key1=bar-path-3}"
      }
      routing_parameters {
        field: "bar"
        path_template: "{routing_key2=bar-path-4}"
      }
    };
  }
}
)""";

  RunRoutingTest(kProto, [](FileDescriptor const* fd) {
    auto const& method = *fd->service(0)->method(0);
    auto info = ParseExplicitRoutingHeader(method);
    EXPECT_THAT(
        info,
        UnorderedElementsAre(
            Pair("routing_key1", ElementsAre(RP("bar", "(bar-path-3)"),
                                             RP("foo", "(foo-path-1)"))),
            Pair("routing_key2", ElementsAre(RP("bar", "(bar-path-4)"),
                                             RP("foo", "(foo-path-2)")))));
  });
}

TEST(ParseExplicitRoutingHeaderTest, HandlesFieldNameConflict) {
  auto constexpr kProto = R"""(
message Foo {
  string namespace = 1;
}

service Service0 {
  rpc Method0(Foo) returns (Foo) {
    option (google.api.routing) = {
      routing_parameters {
        field: "namespace"
      }
    };
  }
}
)""";

  RunRoutingTest(kProto, [](FileDescriptor const* fd) {
    auto const& method = *fd->service(0)->method(0);
    auto info = ParseExplicitRoutingHeader(method);
    // Note that while the field name has been modified so that it does not
    // conflict with the C++ keyword, the routing key must not change.
    EXPECT_THAT(info, UnorderedElementsAre(Pair(
                          "namespace", ElementsAre(RP("namespace_", "(.*)")))));
  });
}

}  // namespace
}  // namespace generator_internal
}  // namespace cloud
}  // namespace google
