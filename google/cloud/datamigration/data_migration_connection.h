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
// source: google/cloud/clouddms/v1/clouddms.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAMIGRATION_DATA_MIGRATION_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAMIGRATION_DATA_MIGRATION_CONNECTION_H

#include "google/cloud/datamigration/data_migration_connection_idempotency_policy.h"
#include "google/cloud/datamigration/internal/data_migration_retry_traits.h"
#include "google/cloud/datamigration/internal/data_migration_stub.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace datamigration {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using DataMigrationServiceRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        datamigration_internal::DataMigrationServiceRetryTraits>;

using DataMigrationServiceLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        datamigration_internal::DataMigrationServiceRetryTraits>;

using DataMigrationServiceLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        datamigration_internal::DataMigrationServiceRetryTraits>;

/**
 * The `DataMigrationServiceConnection` object for `DataMigrationServiceClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `DataMigrationServiceClient`. This allows users to inject custom
 * behavior (e.g., with a Google Mock object) when writing tests that use
 * objects of type `DataMigrationServiceClient`.
 *
 * To create a concrete instance, see `MakeDataMigrationServiceConnection()`.
 *
 * For mocking, see `datamigration_mocks::MockDataMigrationServiceConnection`.
 */
class DataMigrationServiceConnection {
 public:
  virtual ~DataMigrationServiceConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StreamRange<google::cloud::clouddms::v1::MigrationJob>
  ListMigrationJobs(
      google::cloud::clouddms::v1::ListMigrationJobsRequest request);

  virtual StatusOr<google::cloud::clouddms::v1::MigrationJob> GetMigrationJob(
      google::cloud::clouddms::v1::GetMigrationJobRequest const& request);

  virtual future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
  CreateMigrationJob(
      google::cloud::clouddms::v1::CreateMigrationJobRequest const& request);

  virtual future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
  UpdateMigrationJob(
      google::cloud::clouddms::v1::UpdateMigrationJobRequest const& request);

  virtual future<StatusOr<google::cloud::clouddms::v1::OperationMetadata>>
  DeleteMigrationJob(
      google::cloud::clouddms::v1::DeleteMigrationJobRequest const& request);

  virtual future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
  StartMigrationJob(
      google::cloud::clouddms::v1::StartMigrationJobRequest const& request);

  virtual future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
  StopMigrationJob(
      google::cloud::clouddms::v1::StopMigrationJobRequest const& request);

  virtual future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
  ResumeMigrationJob(
      google::cloud::clouddms::v1::ResumeMigrationJobRequest const& request);

  virtual future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
  PromoteMigrationJob(
      google::cloud::clouddms::v1::PromoteMigrationJobRequest const& request);

  virtual future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
  VerifyMigrationJob(
      google::cloud::clouddms::v1::VerifyMigrationJobRequest const& request);

  virtual future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
  RestartMigrationJob(
      google::cloud::clouddms::v1::RestartMigrationJobRequest const& request);

  virtual StatusOr<google::cloud::clouddms::v1::SshScript> GenerateSshScript(
      google::cloud::clouddms::v1::GenerateSshScriptRequest const& request);

  virtual StreamRange<google::cloud::clouddms::v1::ConnectionProfile>
  ListConnectionProfiles(
      google::cloud::clouddms::v1::ListConnectionProfilesRequest request);

  virtual StatusOr<google::cloud::clouddms::v1::ConnectionProfile>
  GetConnectionProfile(
      google::cloud::clouddms::v1::GetConnectionProfileRequest const& request);

  virtual future<StatusOr<google::cloud::clouddms::v1::ConnectionProfile>>
  CreateConnectionProfile(
      google::cloud::clouddms::v1::CreateConnectionProfileRequest const&
          request);

  virtual future<StatusOr<google::cloud::clouddms::v1::ConnectionProfile>>
  UpdateConnectionProfile(
      google::cloud::clouddms::v1::UpdateConnectionProfileRequest const&
          request);

  virtual future<StatusOr<google::cloud::clouddms::v1::OperationMetadata>>
  DeleteConnectionProfile(
      google::cloud::clouddms::v1::DeleteConnectionProfileRequest const&
          request);
};

/**
 * A factory function to construct an object of type
 * `DataMigrationServiceConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of
 * DataMigrationServiceClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `DataMigrationServiceConnection`. Expected options are any of the
 * types in the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::datamigration::DataMigrationServicePolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `DataMigrationServiceConnection`
 * created by this function.
 */
std::shared_ptr<DataMigrationServiceConnection>
MakeDataMigrationServiceConnection(Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datamigration
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAMIGRATION_DATA_MIGRATION_CONNECTION_H
