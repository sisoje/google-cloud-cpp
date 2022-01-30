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
// source: google/monitoring/dashboard/v1/dashboards_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_DASHBOARDS_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_DASHBOARDS_METADATA_DECORATOR_H

#include "google/cloud/monitoring/internal/dashboards_stub.h"
#include "google/cloud/version.h"
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class DashboardsServiceMetadata : public DashboardsServiceStub {
 public:
  ~DashboardsServiceMetadata() override = default;
  explicit DashboardsServiceMetadata(
      std::shared_ptr<DashboardsServiceStub> child);

  StatusOr<google::monitoring::dashboard::v1::Dashboard> CreateDashboard(
      grpc::ClientContext& context,
      google::monitoring::dashboard::v1::CreateDashboardRequest const& request)
      override;

  StatusOr<google::monitoring::dashboard::v1::ListDashboardsResponse>
  ListDashboards(grpc::ClientContext& context,
                 google::monitoring::dashboard::v1::ListDashboardsRequest const&
                     request) override;

  StatusOr<google::monitoring::dashboard::v1::Dashboard> GetDashboard(
      grpc::ClientContext& context,
      google::monitoring::dashboard::v1::GetDashboardRequest const& request)
      override;

  Status DeleteDashboard(
      grpc::ClientContext& context,
      google::monitoring::dashboard::v1::DeleteDashboardRequest const& request)
      override;

  StatusOr<google::monitoring::dashboard::v1::Dashboard> UpdateDashboard(
      grpc::ClientContext& context,
      google::monitoring::dashboard::v1::UpdateDashboardRequest const& request)
      override;

 private:
  void SetMetadata(grpc::ClientContext& context,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context);

  std::shared_ptr<DashboardsServiceStub> child_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_DASHBOARDS_METADATA_DECORATOR_H
