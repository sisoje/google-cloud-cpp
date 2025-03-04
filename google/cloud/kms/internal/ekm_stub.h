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
// source: google/cloud/kms/v1/ekm_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_INTERNAL_EKM_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_INTERNAL_EKM_STUB_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/kms/v1/ekm_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace kms_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class EkmServiceStub {
 public:
  virtual ~EkmServiceStub() = 0;

  virtual StatusOr<google::cloud::kms::v1::ListEkmConnectionsResponse>
  ListEkmConnections(
      grpc::ClientContext& context,
      google::cloud::kms::v1::ListEkmConnectionsRequest const& request) = 0;

  virtual StatusOr<google::cloud::kms::v1::EkmConnection> GetEkmConnection(
      grpc::ClientContext& context,
      google::cloud::kms::v1::GetEkmConnectionRequest const& request) = 0;

  virtual StatusOr<google::cloud::kms::v1::EkmConnection> CreateEkmConnection(
      grpc::ClientContext& context,
      google::cloud::kms::v1::CreateEkmConnectionRequest const& request) = 0;

  virtual StatusOr<google::cloud::kms::v1::EkmConnection> UpdateEkmConnection(
      grpc::ClientContext& context,
      google::cloud::kms::v1::UpdateEkmConnectionRequest const& request) = 0;
};

class DefaultEkmServiceStub : public EkmServiceStub {
 public:
  explicit DefaultEkmServiceStub(
      std::unique_ptr<google::cloud::kms::v1::EkmService::StubInterface>
          grpc_stub)
      : grpc_stub_(std::move(grpc_stub)) {}

  StatusOr<google::cloud::kms::v1::ListEkmConnectionsResponse>
  ListEkmConnections(grpc::ClientContext& client_context,
                     google::cloud::kms::v1::ListEkmConnectionsRequest const&
                         request) override;

  StatusOr<google::cloud::kms::v1::EkmConnection> GetEkmConnection(
      grpc::ClientContext& client_context,
      google::cloud::kms::v1::GetEkmConnectionRequest const& request) override;

  StatusOr<google::cloud::kms::v1::EkmConnection> CreateEkmConnection(
      grpc::ClientContext& client_context,
      google::cloud::kms::v1::CreateEkmConnectionRequest const& request)
      override;

  StatusOr<google::cloud::kms::v1::EkmConnection> UpdateEkmConnection(
      grpc::ClientContext& client_context,
      google::cloud::kms::v1::UpdateEkmConnectionRequest const& request)
      override;

 private:
  std::unique_ptr<google::cloud::kms::v1::EkmService::StubInterface> grpc_stub_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace kms_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_INTERNAL_EKM_STUB_H
