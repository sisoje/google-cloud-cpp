// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/dialogflow/cx/v3/session.proto

#include "google/cloud/dialogflow_cx/sessions_connection.h"
#include "google/cloud/dialogflow_cx/internal/sessions_connection_impl.h"
#include "google/cloud/dialogflow_cx/internal/sessions_option_defaults.h"
#include "google/cloud/dialogflow_cx/internal/sessions_stub_factory.h"
#include "google/cloud/dialogflow_cx/sessions_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SessionsConnection::~SessionsConnection() = default;

StatusOr<google::cloud::dialogflow::cx::v3::DetectIntentResponse>
SessionsConnection::DetectIntent(
    google::cloud::dialogflow::cx::v3::DetectIntentRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::cloud::dialogflow::cx::v3::StreamingDetectIntentRequest,
    google::cloud::dialogflow::cx::v3::StreamingDetectIntentResponse>>
SessionsConnection::AsyncStreamingDetectIntent() {
  return absl::make_unique<
      ::google::cloud::internal::AsyncStreamingReadWriteRpcError<
          google::cloud::dialogflow::cx::v3::StreamingDetectIntentRequest,
          google::cloud::dialogflow::cx::v3::StreamingDetectIntentResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::cloud::dialogflow::cx::v3::MatchIntentResponse>
SessionsConnection::MatchIntent(
    google::cloud::dialogflow::cx::v3::MatchIntentRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::dialogflow::cx::v3::FulfillIntentResponse>
SessionsConnection::FulfillIntent(
    google::cloud::dialogflow::cx::v3::FulfillIntentRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<SessionsConnection> MakeSessionsConnection(
    std::string const& location, Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UnifiedCredentialsOptionList,
                                 SessionsPolicyOptionList>(options, __func__);
  options = dialogflow_cx_internal::SessionsDefaultOptions(location,
                                                           std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = dialogflow_cx_internal::CreateDefaultSessionsStub(
      background->cq(), options);
  return std::make_shared<dialogflow_cx_internal::SessionsConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

std::shared_ptr<SessionsConnection> MakeSessionsConnection(Options options) {
  return MakeSessionsConnection(std::string{}, std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx
}  // namespace cloud
}  // namespace google
