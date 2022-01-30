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
// source: google/monitoring/v3/query_service.proto

#include "google/cloud/monitoring/query_connection.h"
#include "google/cloud/monitoring/internal/query_connection_impl.h"
#include "google/cloud/monitoring/internal/query_option_defaults.h"
#include "google/cloud/monitoring/internal/query_stub_factory.h"
#include "google/cloud/monitoring/query_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

QueryServiceConnection::~QueryServiceConnection() = default;

StreamRange<google::monitoring::v3::TimeSeriesData>
QueryServiceConnection::QueryTimeSeries(
    google::monitoring::v3::QueryTimeSeriesRequest request) {
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::monitoring::v3::TimeSeriesData>>(
      std::move(request),
      [](google::monitoring::v3::QueryTimeSeriesRequest const&) {
        return StatusOr<google::monitoring::v3::QueryTimeSeriesResponse>{};
      },
      [](google::monitoring::v3::QueryTimeSeriesResponse const&) {
        return std::vector<google::monitoring::v3::TimeSeriesData>();
      });
}

std::shared_ptr<QueryServiceConnection> MakeQueryServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 QueryServicePolicyOptionList>(options,
                                                               __func__);
  options = monitoring_internal::QueryServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = monitoring_internal::CreateDefaultQueryServiceStub(
      background->cq(), options);
  return std::make_shared<monitoring_internal::QueryServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<monitoring::QueryServiceConnection> MakeQueryServiceConnection(
    std::shared_ptr<QueryServiceStub> stub, Options options) {
  options = QueryServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<monitoring_internal::QueryServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google
