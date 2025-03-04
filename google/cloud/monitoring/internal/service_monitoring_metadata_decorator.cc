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
// source: google/monitoring/v3/service_service.proto

#include "google/cloud/monitoring/internal/service_monitoring_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/monitoring/v3/service_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ServiceMonitoringServiceMetadata::ServiceMonitoringServiceMetadata(
    std::shared_ptr<ServiceMonitoringServiceStub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::monitoring::v3::Service>
ServiceMonitoringServiceMetadata::CreateService(
    grpc::ClientContext& context,
    google::monitoring::v3::CreateServiceRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->CreateService(context, request);
}

StatusOr<google::monitoring::v3::Service>
ServiceMonitoringServiceMetadata::GetService(
    grpc::ClientContext& context,
    google::monitoring::v3::GetServiceRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetService(context, request);
}

StatusOr<google::monitoring::v3::ListServicesResponse>
ServiceMonitoringServiceMetadata::ListServices(
    grpc::ClientContext& context,
    google::monitoring::v3::ListServicesRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListServices(context, request);
}

StatusOr<google::monitoring::v3::Service>
ServiceMonitoringServiceMetadata::UpdateService(
    grpc::ClientContext& context,
    google::monitoring::v3::UpdateServiceRequest const& request) {
  SetMetadata(context, "service.name=" + request.service().name());
  return child_->UpdateService(context, request);
}

Status ServiceMonitoringServiceMetadata::DeleteService(
    grpc::ClientContext& context,
    google::monitoring::v3::DeleteServiceRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->DeleteService(context, request);
}

StatusOr<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceMetadata::CreateServiceLevelObjective(
    grpc::ClientContext& context,
    google::monitoring::v3::CreateServiceLevelObjectiveRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->CreateServiceLevelObjective(context, request);
}

StatusOr<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceMetadata::GetServiceLevelObjective(
    grpc::ClientContext& context,
    google::monitoring::v3::GetServiceLevelObjectiveRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetServiceLevelObjective(context, request);
}

StatusOr<google::monitoring::v3::ListServiceLevelObjectivesResponse>
ServiceMonitoringServiceMetadata::ListServiceLevelObjectives(
    grpc::ClientContext& context,
    google::monitoring::v3::ListServiceLevelObjectivesRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListServiceLevelObjectives(context, request);
}

StatusOr<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceMetadata::UpdateServiceLevelObjective(
    grpc::ClientContext& context,
    google::monitoring::v3::UpdateServiceLevelObjectiveRequest const& request) {
  SetMetadata(context, "service_level_objective.name=" +
                           request.service_level_objective().name());
  return child_->UpdateServiceLevelObjective(context, request);
}

Status ServiceMonitoringServiceMetadata::DeleteServiceLevelObjective(
    grpc::ClientContext& context,
    google::monitoring::v3::DeleteServiceLevelObjectiveRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->DeleteServiceLevelObjective(context, request);
}

void ServiceMonitoringServiceMetadata::SetMetadata(
    grpc::ClientContext& context, std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void ServiceMonitoringServiceMetadata::SetMetadata(
    grpc::ClientContext& context) {
  context.AddMetadata("x-goog-api-client", api_client_header_);
  auto const& options = internal::CurrentOptions();
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google
