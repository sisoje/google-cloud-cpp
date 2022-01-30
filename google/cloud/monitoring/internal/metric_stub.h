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
// source: google/monitoring/v3/metric_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_METRIC_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_METRIC_STUB_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/monitoring/v3/metric_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MetricServiceStub {
 public:
  virtual ~MetricServiceStub() = 0;

  virtual StatusOr<
      google::monitoring::v3::ListMonitoredResourceDescriptorsResponse>
  ListMonitoredResourceDescriptors(
      grpc::ClientContext& context,
      google::monitoring::v3::ListMonitoredResourceDescriptorsRequest const&
          request) = 0;

  virtual StatusOr<google::api::MonitoredResourceDescriptor>
  GetMonitoredResourceDescriptor(
      grpc::ClientContext& context,
      google::monitoring::v3::GetMonitoredResourceDescriptorRequest const&
          request) = 0;

  virtual StatusOr<google::monitoring::v3::ListMetricDescriptorsResponse>
  ListMetricDescriptors(
      grpc::ClientContext& context,
      google::monitoring::v3::ListMetricDescriptorsRequest const& request) = 0;

  virtual StatusOr<google::api::MetricDescriptor> GetMetricDescriptor(
      grpc::ClientContext& context,
      google::monitoring::v3::GetMetricDescriptorRequest const& request) = 0;

  virtual StatusOr<google::api::MetricDescriptor> CreateMetricDescriptor(
      grpc::ClientContext& context,
      google::monitoring::v3::CreateMetricDescriptorRequest const& request) = 0;

  virtual Status DeleteMetricDescriptor(
      grpc::ClientContext& context,
      google::monitoring::v3::DeleteMetricDescriptorRequest const& request) = 0;

  virtual StatusOr<google::monitoring::v3::ListTimeSeriesResponse>
  ListTimeSeries(
      grpc::ClientContext& context,
      google::monitoring::v3::ListTimeSeriesRequest const& request) = 0;

  virtual Status CreateTimeSeries(
      grpc::ClientContext& context,
      google::monitoring::v3::CreateTimeSeriesRequest const& request) = 0;

  virtual Status CreateServiceTimeSeries(
      grpc::ClientContext& context,
      google::monitoring::v3::CreateTimeSeriesRequest const& request) = 0;
};

class DefaultMetricServiceStub : public MetricServiceStub {
 public:
  explicit DefaultMetricServiceStub(
      std::unique_ptr<google::monitoring::v3::MetricService::StubInterface>
          grpc_stub)
      : grpc_stub_(std::move(grpc_stub)) {}

  StatusOr<google::monitoring::v3::ListMonitoredResourceDescriptorsResponse>
  ListMonitoredResourceDescriptors(
      grpc::ClientContext& client_context,
      google::monitoring::v3::ListMonitoredResourceDescriptorsRequest const&
          request) override;

  StatusOr<google::api::MonitoredResourceDescriptor>
  GetMonitoredResourceDescriptor(
      grpc::ClientContext& client_context,
      google::monitoring::v3::GetMonitoredResourceDescriptorRequest const&
          request) override;

  StatusOr<google::monitoring::v3::ListMetricDescriptorsResponse>
  ListMetricDescriptors(
      grpc::ClientContext& client_context,
      google::monitoring::v3::ListMetricDescriptorsRequest const& request)
      override;

  StatusOr<google::api::MetricDescriptor> GetMetricDescriptor(
      grpc::ClientContext& client_context,
      google::monitoring::v3::GetMetricDescriptorRequest const& request)
      override;

  StatusOr<google::api::MetricDescriptor> CreateMetricDescriptor(
      grpc::ClientContext& client_context,
      google::monitoring::v3::CreateMetricDescriptorRequest const& request)
      override;

  Status DeleteMetricDescriptor(
      grpc::ClientContext& client_context,
      google::monitoring::v3::DeleteMetricDescriptorRequest const& request)
      override;

  StatusOr<google::monitoring::v3::ListTimeSeriesResponse> ListTimeSeries(
      grpc::ClientContext& client_context,
      google::monitoring::v3::ListTimeSeriesRequest const& request) override;

  Status CreateTimeSeries(
      grpc::ClientContext& client_context,
      google::monitoring::v3::CreateTimeSeriesRequest const& request) override;

  Status CreateServiceTimeSeries(
      grpc::ClientContext& client_context,
      google::monitoring::v3::CreateTimeSeriesRequest const& request) override;

 private:
  std::unique_ptr<google::monitoring::v3::MetricService::StubInterface>
      grpc_stub_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_METRIC_STUB_H
