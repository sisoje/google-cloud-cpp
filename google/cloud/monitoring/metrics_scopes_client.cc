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
// source: google/monitoring/metricsscope/v1/metrics_scopes.proto

#include "google/cloud/monitoring/metrics_scopes_client.h"
#include "google/cloud/monitoring/internal/metrics_scopes_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

MetricsScopesClient::MetricsScopesClient(
    std::shared_ptr<MetricsScopesConnection> connection, Options options)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(options), monitoring_internal::MetricsScopesDefaultOptions(
                                  connection_->options()))) {}
MetricsScopesClient::~MetricsScopesClient() = default;

StatusOr<google::monitoring::metricsscope::v1::MetricsScope>
MetricsScopesClient::GetMetricsScope(std::string const& name, Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::metricsscope::v1::GetMetricsScopeRequest request;
  request.set_name(name);
  return connection_->GetMetricsScope(request);
}

StatusOr<google::monitoring::metricsscope::v1::MetricsScope>
MetricsScopesClient::GetMetricsScope(
    google::monitoring::metricsscope::v1::GetMetricsScopeRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->GetMetricsScope(request);
}

StatusOr<google::monitoring::metricsscope::v1::
             ListMetricsScopesByMonitoredProjectResponse>
MetricsScopesClient::ListMetricsScopesByMonitoredProject(
    google::monitoring::metricsscope::v1::
        ListMetricsScopesByMonitoredProjectRequest const& request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->ListMetricsScopesByMonitoredProject(request);
}

future<StatusOr<google::monitoring::metricsscope::v1::MonitoredProject>>
MetricsScopesClient::CreateMonitoredProject(
    std::string const& parent,
    google::monitoring::metricsscope::v1::MonitoredProject const&
        monitored_project,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::metricsscope::v1::CreateMonitoredProjectRequest request;
  request.set_parent(parent);
  *request.mutable_monitored_project() = monitored_project;
  return connection_->CreateMonitoredProject(request);
}

future<StatusOr<google::monitoring::metricsscope::v1::MonitoredProject>>
MetricsScopesClient::CreateMonitoredProject(
    google::monitoring::metricsscope::v1::CreateMonitoredProjectRequest const&
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->CreateMonitoredProject(request);
}

future<StatusOr<google::monitoring::metricsscope::v1::OperationMetadata>>
MetricsScopesClient::DeleteMonitoredProject(std::string const& name,
                                            Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  google::monitoring::metricsscope::v1::DeleteMonitoredProjectRequest request;
  request.set_name(name);
  return connection_->DeleteMonitoredProject(request);
}

future<StatusOr<google::monitoring::metricsscope::v1::OperationMetadata>>
MetricsScopesClient::DeleteMonitoredProject(
    google::monitoring::metricsscope::v1::DeleteMonitoredProjectRequest const&
        request,
    Options options) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(options), options_));
  return connection_->DeleteMonitoredProject(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring
}  // namespace cloud
}  // namespace google
