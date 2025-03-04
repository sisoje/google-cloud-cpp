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
// source: google/cloud/dialogflow/v2/session_entity_type.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_SESSION_ENTITY_TYPES_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_SESSION_ENTITY_TYPES_METADATA_DECORATOR_H

#include "google/cloud/dialogflow_es/internal/session_entity_types_stub.h"
#include "google/cloud/version.h"
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class SessionEntityTypesMetadata : public SessionEntityTypesStub {
 public:
  ~SessionEntityTypesMetadata() override = default;
  explicit SessionEntityTypesMetadata(
      std::shared_ptr<SessionEntityTypesStub> child);

  StatusOr<google::cloud::dialogflow::v2::ListSessionEntityTypesResponse>
  ListSessionEntityTypes(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::ListSessionEntityTypesRequest const&
          request) override;

  StatusOr<google::cloud::dialogflow::v2::SessionEntityType>
  GetSessionEntityType(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::GetSessionEntityTypeRequest const& request)
      override;

  StatusOr<google::cloud::dialogflow::v2::SessionEntityType>
  CreateSessionEntityType(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::CreateSessionEntityTypeRequest const&
          request) override;

  StatusOr<google::cloud::dialogflow::v2::SessionEntityType>
  UpdateSessionEntityType(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::UpdateSessionEntityTypeRequest const&
          request) override;

  Status DeleteSessionEntityType(
      grpc::ClientContext& context,
      google::cloud::dialogflow::v2::DeleteSessionEntityTypeRequest const&
          request) override;

 private:
  void SetMetadata(grpc::ClientContext& context,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context);

  std::shared_ptr<SessionEntityTypesStub> child_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_INTERNAL_SESSION_ENTITY_TYPES_METADATA_DECORATOR_H
