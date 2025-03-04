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

#include "google/cloud/datamigration/internal/data_migration_connection_impl.h"
#include "google/cloud/datamigration/internal/data_migration_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace datamigration_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DataMigrationServiceConnectionImpl::DataMigrationServiceConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<datamigration_internal::DataMigrationServiceStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options), DataMigrationServiceConnection::options())) {}

StreamRange<google::cloud::clouddms::v1::MigrationJob>
DataMigrationServiceConnectionImpl::ListMigrationJobs(
    google::cloud::clouddms::v1::ListMigrationJobsRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry =
      std::shared_ptr<datamigration::DataMigrationServiceRetryPolicy const>(
          retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListMigrationJobs(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::clouddms::v1::MigrationJob>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::clouddms::v1::ListMigrationJobsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::clouddms::v1::ListMigrationJobsRequest const&
                       request) {
              return stub->ListMigrationJobs(context, request);
            },
            r, function_name);
      },
      [](google::cloud::clouddms::v1::ListMigrationJobsResponse r) {
        std::vector<google::cloud::clouddms::v1::MigrationJob> result(
            r.migration_jobs().size());
        auto& messages = *r.mutable_migration_jobs();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::clouddms::v1::MigrationJob>
DataMigrationServiceConnectionImpl::GetMigrationJob(
    google::cloud::clouddms::v1::GetMigrationJobRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetMigrationJob(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::clouddms::v1::GetMigrationJobRequest const& request) {
        return stub_->GetMigrationJob(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceConnectionImpl::CreateMigrationJob(
    google::cloud::clouddms::v1::CreateMigrationJobRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::MigrationJob>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::CreateMigrationJobRequest const&
                 request) {
        return stub->AsyncCreateMigrationJob(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::clouddms::v1::MigrationJob>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateMigrationJob(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceConnectionImpl::UpdateMigrationJob(
    google::cloud::clouddms::v1::UpdateMigrationJobRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::MigrationJob>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::UpdateMigrationJobRequest const&
                 request) {
        return stub->AsyncUpdateMigrationJob(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::clouddms::v1::MigrationJob>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateMigrationJob(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::clouddms::v1::OperationMetadata>>
DataMigrationServiceConnectionImpl::DeleteMigrationJob(
    google::cloud::clouddms::v1::DeleteMigrationJobRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::OperationMetadata>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::DeleteMigrationJobRequest const&
                 request) {
        return stub->AsyncDeleteMigrationJob(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultMetadata<
          google::cloud::clouddms::v1::OperationMetadata>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteMigrationJob(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceConnectionImpl::StartMigrationJob(
    google::cloud::clouddms::v1::StartMigrationJobRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::MigrationJob>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::StartMigrationJobRequest const&
                 request) {
        return stub->AsyncStartMigrationJob(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::clouddms::v1::MigrationJob>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->StartMigrationJob(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceConnectionImpl::StopMigrationJob(
    google::cloud::clouddms::v1::StopMigrationJobRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::MigrationJob>(
      background_->cq(), request,
      [stub](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::clouddms::v1::StopMigrationJobRequest const& request) {
        return stub->AsyncStopMigrationJob(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::clouddms::v1::MigrationJob>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->StopMigrationJob(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceConnectionImpl::ResumeMigrationJob(
    google::cloud::clouddms::v1::ResumeMigrationJobRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::MigrationJob>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::ResumeMigrationJobRequest const&
                 request) {
        return stub->AsyncResumeMigrationJob(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::clouddms::v1::MigrationJob>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->ResumeMigrationJob(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceConnectionImpl::PromoteMigrationJob(
    google::cloud::clouddms::v1::PromoteMigrationJobRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::MigrationJob>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::PromoteMigrationJobRequest const&
                 request) {
        return stub->AsyncPromoteMigrationJob(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::clouddms::v1::MigrationJob>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->PromoteMigrationJob(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceConnectionImpl::VerifyMigrationJob(
    google::cloud::clouddms::v1::VerifyMigrationJobRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::MigrationJob>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::VerifyMigrationJobRequest const&
                 request) {
        return stub->AsyncVerifyMigrationJob(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::clouddms::v1::MigrationJob>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->VerifyMigrationJob(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::clouddms::v1::MigrationJob>>
DataMigrationServiceConnectionImpl::RestartMigrationJob(
    google::cloud::clouddms::v1::RestartMigrationJobRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::MigrationJob>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::RestartMigrationJobRequest const&
                 request) {
        return stub->AsyncRestartMigrationJob(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::clouddms::v1::MigrationJob>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->RestartMigrationJob(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::clouddms::v1::SshScript>
DataMigrationServiceConnectionImpl::GenerateSshScript(
    google::cloud::clouddms::v1::GenerateSshScriptRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GenerateSshScript(request),
      [this](grpc::ClientContext& context,
             google::cloud::clouddms::v1::GenerateSshScriptRequest const&
                 request) {
        return stub_->GenerateSshScript(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::clouddms::v1::ConnectionProfile>
DataMigrationServiceConnectionImpl::ListConnectionProfiles(
    google::cloud::clouddms::v1::ListConnectionProfilesRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry =
      std::shared_ptr<datamigration::DataMigrationServiceRetryPolicy const>(
          retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListConnectionProfiles(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::clouddms::v1::ConnectionProfile>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::clouddms::v1::ListConnectionProfilesRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::clouddms::v1::
                       ListConnectionProfilesRequest const& request) {
              return stub->ListConnectionProfiles(context, request);
            },
            r, function_name);
      },
      [](google::cloud::clouddms::v1::ListConnectionProfilesResponse r) {
        std::vector<google::cloud::clouddms::v1::ConnectionProfile> result(
            r.connection_profiles().size());
        auto& messages = *r.mutable_connection_profiles();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::clouddms::v1::ConnectionProfile>
DataMigrationServiceConnectionImpl::GetConnectionProfile(
    google::cloud::clouddms::v1::GetConnectionProfileRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetConnectionProfile(request),
      [this](grpc::ClientContext& context,
             google::cloud::clouddms::v1::GetConnectionProfileRequest const&
                 request) {
        return stub_->GetConnectionProfile(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::clouddms::v1::ConnectionProfile>>
DataMigrationServiceConnectionImpl::CreateConnectionProfile(
    google::cloud::clouddms::v1::CreateConnectionProfileRequest const&
        request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::ConnectionProfile>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::CreateConnectionProfileRequest const&
                 request) {
        return stub->AsyncCreateConnectionProfile(cq, std::move(context),
                                                  request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::clouddms::v1::ConnectionProfile>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateConnectionProfile(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::clouddms::v1::ConnectionProfile>>
DataMigrationServiceConnectionImpl::UpdateConnectionProfile(
    google::cloud::clouddms::v1::UpdateConnectionProfileRequest const&
        request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::ConnectionProfile>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::UpdateConnectionProfileRequest const&
                 request) {
        return stub->AsyncUpdateConnectionProfile(cq, std::move(context),
                                                  request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::clouddms::v1::ConnectionProfile>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateConnectionProfile(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::clouddms::v1::OperationMetadata>>
DataMigrationServiceConnectionImpl::DeleteConnectionProfile(
    google::cloud::clouddms::v1::DeleteConnectionProfileRequest const&
        request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::clouddms::v1::OperationMetadata>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::clouddms::v1::DeleteConnectionProfileRequest const&
                 request) {
        return stub->AsyncDeleteConnectionProfile(cq, std::move(context),
                                                  request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultMetadata<
          google::cloud::clouddms::v1::OperationMetadata>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteConnectionProfile(request), polling_policy(),
      __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datamigration_internal
}  // namespace cloud
}  // namespace google
