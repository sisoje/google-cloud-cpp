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

#include "google/cloud/monitoring/service_monitoring_client.h"
#include "google/cloud/monitoring/internal/service_monitoring_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ServiceMonitoringServiceClient::ServiceMonitoringServiceClient(
    std::shared_ptr<ServiceMonitoringServiceConnection> connection,
    Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options),
          monitoring_internal::ServiceMonitoringServiceDefaultOptions(
              connection_->options()))) {}
ServiceMonitoringServiceClient::~ServiceMonitoringServiceClient() = default;

StatusOr<google::monitoring::v3::Service>
ServiceMonitoringServiceClient::CreateService(
    std::string const& parent, google::monitoring::v3::Service const& service,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::v3::CreateServiceRequest request;
  request.set_parent(parent);
  *request.mutable_service() = service;
  return connection_->CreateService(request);
}

StatusOr<google::monitoring::v3::Service>
ServiceMonitoringServiceClient::CreateService(
    google::monitoring::v3::CreateServiceRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateService(request);
}

StatusOr<google::monitoring::v3::Service>
ServiceMonitoringServiceClient::GetService(std::string const& name,
                                           Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::v3::GetServiceRequest request;
  request.set_name(name);
  return connection_->GetService(request);
}

StatusOr<google::monitoring::v3::Service>
ServiceMonitoringServiceClient::GetService(
    google::monitoring::v3::GetServiceRequest const& request, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetService(request);
}

StreamRange<google::monitoring::v3::Service>
ServiceMonitoringServiceClient::ListServices(std::string const& parent,
                                             Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::v3::ListServicesRequest request;
  request.set_parent(parent);
  return connection_->ListServices(request);
}

StreamRange<google::monitoring::v3::Service>
ServiceMonitoringServiceClient::ListServices(
    google::monitoring::v3::ListServicesRequest request, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListServices(std::move(request));
}

StatusOr<google::monitoring::v3::Service>
ServiceMonitoringServiceClient::UpdateService(
    google::monitoring::v3::Service const& service, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::v3::UpdateServiceRequest request;
  *request.mutable_service() = service;
  return connection_->UpdateService(request);
}

StatusOr<google::monitoring::v3::Service>
ServiceMonitoringServiceClient::UpdateService(
    google::monitoring::v3::UpdateServiceRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateService(request);
}

Status ServiceMonitoringServiceClient::DeleteService(std::string const& name,
                                                     Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::v3::DeleteServiceRequest request;
  request.set_name(name);
  return connection_->DeleteService(request);
}

Status ServiceMonitoringServiceClient::DeleteService(
    google::monitoring::v3::DeleteServiceRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DeleteService(request);
}

StatusOr<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceClient::CreateServiceLevelObjective(
    std::string const& parent,
    google::monitoring::v3::ServiceLevelObjective const&
        service_level_objective,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::v3::CreateServiceLevelObjectiveRequest request;
  request.set_parent(parent);
  *request.mutable_service_level_objective() = service_level_objective;
  return connection_->CreateServiceLevelObjective(request);
}

StatusOr<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceClient::CreateServiceLevelObjective(
    google::monitoring::v3::CreateServiceLevelObjectiveRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateServiceLevelObjective(request);
}

StatusOr<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceClient::GetServiceLevelObjective(
    std::string const& name, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::v3::GetServiceLevelObjectiveRequest request;
  request.set_name(name);
  return connection_->GetServiceLevelObjective(request);
}

StatusOr<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceClient::GetServiceLevelObjective(
    google::monitoring::v3::GetServiceLevelObjectiveRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetServiceLevelObjective(request);
}

StreamRange<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceClient::ListServiceLevelObjectives(
    std::string const& parent, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::v3::ListServiceLevelObjectivesRequest request;
  request.set_parent(parent);
  return connection_->ListServiceLevelObjectives(request);
}

StreamRange<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceClient::ListServiceLevelObjectives(
    google::monitoring::v3::ListServiceLevelObjectivesRequest request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListServiceLevelObjectives(std::move(request));
}

StatusOr<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceClient::UpdateServiceLevelObjective(
    google::monitoring::v3::ServiceLevelObjective const&
        service_level_objective,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::v3::UpdateServiceLevelObjectiveRequest request;
  *request.mutable_service_level_objective() = service_level_objective;
  return connection_->UpdateServiceLevelObjective(request);
}

StatusOr<google::monitoring::v3::ServiceLevelObjective>
ServiceMonitoringServiceClient::UpdateServiceLevelObjective(
    google::monitoring::v3::UpdateServiceLevelObjectiveRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->UpdateServiceLevelObjective(request);
}

Status ServiceMonitoringServiceClient::DeleteServiceLevelObjective(
    std::string const& name, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::v3::DeleteServiceLevelObjectiveRequest request;
  request.set_name(name);
  return connection_->DeleteServiceLevelObjective(request);
}

Status ServiceMonitoringServiceClient::DeleteServiceLevelObjective(
    google::monitoring::v3::DeleteServiceLevelObjectiveRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DeleteServiceLevelObjective(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring
}  // namespace cloud
}  // namespace google
