// Copyright 2021 Google LLC
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
// source: generator/integration_tests/test.proto
#ifndef GOOGLE_CLOUD_CPP_GENERATOR_INTEGRATION_TESTS_GOLDEN_GOLDEN_KITCHEN_SINK_CONNECTION_GCPCXX_PB_H
#define GOOGLE_CLOUD_CPP_GENERATOR_INTEGRATION_TESTS_GOLDEN_GOLDEN_KITCHEN_SINK_CONNECTION_GCPCXX_PB_H

#include "generator/integration_tests/golden/golden_kitchen_sink_connection_idempotency_policy.gcpcxx.pb.h"
#include "generator/integration_tests/golden/internal/golden_kitchen_sink_stub.gcpcxx.pb.h"
#include "generator/integration_tests/golden/retry_traits.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/connection_options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace golden {
inline namespace GOOGLE_CLOUD_CPP_GENERATED_NS {

struct GoldenKitchenSinkConnectionOptionsTraits {
  static std::string default_endpoint();
  static std::string user_agent_prefix();
  static int default_num_channels();
};

using GoldenKitchenSinkConnectionOptions =
  google::cloud::ConnectionOptions<GoldenKitchenSinkConnectionOptionsTraits>;

using GoldenKitchenSinkRetryPolicy = google::cloud::internal::TraitBasedRetryPolicy<
    golden_internal::GoldenKitchenSinkRetryTraits>;

using GoldenKitchenSinkLimitedTimeRetryPolicy = google::cloud::internal::LimitedTimeRetryPolicy<
    golden_internal::GoldenKitchenSinkRetryTraits>;

using GoldenKitchenSinkLimitedErrorCountRetryPolicy =
    google::cloud::internal::LimitedErrorCountRetryPolicy<
        golden_internal::GoldenKitchenSinkRetryTraits>;

void GoldenKitchenSinkTailLogEntriesStreamingUpdater(
    ::google::test::admin::database::v1::TailLogEntriesResponse const& response,
    ::google::test::admin::database::v1::TailLogEntriesRequest& request);

class GoldenKitchenSinkConnection {
 public:
  virtual ~GoldenKitchenSinkConnection() = 0;

  virtual StatusOr<::google::test::admin::database::v1::GenerateAccessTokenResponse>
  GenerateAccessToken(::google::test::admin::database::v1::GenerateAccessTokenRequest const& request);

  virtual StatusOr<::google::test::admin::database::v1::GenerateIdTokenResponse>
  GenerateIdToken(::google::test::admin::database::v1::GenerateIdTokenRequest const& request);

  virtual StatusOr<::google::test::admin::database::v1::WriteLogEntriesResponse>
  WriteLogEntries(::google::test::admin::database::v1::WriteLogEntriesRequest const& request);

  virtual StreamRange<std::string>
  ListLogs(::google::test::admin::database::v1::ListLogsRequest request);

  virtual StreamRange<::google::test::admin::database::v1::TailLogEntriesResponse>
  TailLogEntries(::google::test::admin::database::v1::TailLogEntriesRequest request);

};

std::shared_ptr<GoldenKitchenSinkConnection> MakeGoldenKitchenSinkConnection(
    GoldenKitchenSinkConnectionOptions const& options = GoldenKitchenSinkConnectionOptions());

std::shared_ptr<GoldenKitchenSinkConnection> MakeGoldenKitchenSinkConnection(
    GoldenKitchenSinkConnectionOptions const& options,
    std::unique_ptr<GoldenKitchenSinkRetryPolicy> retry_policy,
    std::unique_ptr<BackoffPolicy> backoff_policy,
    std::unique_ptr<GoldenKitchenSinkConnectionIdempotencyPolicy> idempotency_policy);

std::shared_ptr<GoldenKitchenSinkConnection> MakeGoldenKitchenSinkConnection(
    std::shared_ptr<golden_internal::GoldenKitchenSinkStub> stub,
    std::unique_ptr<GoldenKitchenSinkRetryPolicy> retry_policy,
    std::unique_ptr<BackoffPolicy> backoff_policy,
    std::unique_ptr<GoldenKitchenSinkConnectionIdempotencyPolicy> idempotency_policy);

}  // namespace GOOGLE_CLOUD_CPP_GENERATED_NS
}  // namespace golden
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GENERATOR_INTEGRATION_TESTS_GOLDEN_GOLDEN_KITCHEN_SINK_CONNECTION_GCPCXX_PB_H
