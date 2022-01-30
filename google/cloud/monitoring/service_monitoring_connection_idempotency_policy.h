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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_SERVICE_MONITORING_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_SERVICE_MONITORING_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/monitoring/v3/service_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace monitoring {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ServiceMonitoringServiceConnectionIdempotencyPolicy {
 public:
  virtual ~ServiceMonitoringServiceConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<ServiceMonitoringServiceConnectionIdempotencyPolicy>
  clone() const = 0;

  virtual google::cloud::Idempotency CreateService(
      google::monitoring::v3::CreateServiceRequest const& request) = 0;

  virtual google::cloud::Idempotency GetService(
      google::monitoring::v3::GetServiceRequest const& request) = 0;

  virtual google::cloud::Idempotency ListServices(
      google::monitoring::v3::ListServicesRequest request) = 0;

  virtual google::cloud::Idempotency UpdateService(
      google::monitoring::v3::UpdateServiceRequest const& request) = 0;

  virtual google::cloud::Idempotency DeleteService(
      google::monitoring::v3::DeleteServiceRequest const& request) = 0;

  virtual google::cloud::Idempotency CreateServiceLevelObjective(
      google::monitoring::v3::CreateServiceLevelObjectiveRequest const&
          request) = 0;

  virtual google::cloud::Idempotency GetServiceLevelObjective(
      google::monitoring::v3::GetServiceLevelObjectiveRequest const&
          request) = 0;

  virtual google::cloud::Idempotency ListServiceLevelObjectives(
      google::monitoring::v3::ListServiceLevelObjectivesRequest request) = 0;

  virtual google::cloud::Idempotency UpdateServiceLevelObjective(
      google::monitoring::v3::UpdateServiceLevelObjectiveRequest const&
          request) = 0;

  virtual google::cloud::Idempotency DeleteServiceLevelObjective(
      google::monitoring::v3::DeleteServiceLevelObjectiveRequest const&
          request) = 0;
};

std::unique_ptr<ServiceMonitoringServiceConnectionIdempotencyPolicy>
MakeDefaultServiceMonitoringServiceConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_SERVICE_MONITORING_CONNECTION_IDEMPOTENCY_POLICY_H
