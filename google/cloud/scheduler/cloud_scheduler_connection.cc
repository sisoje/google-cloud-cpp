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
// source: google/cloud/scheduler/v1/cloudscheduler.proto

#include "google/cloud/scheduler/cloud_scheduler_connection.h"
#include "google/cloud/scheduler/cloud_scheduler_options.h"
#include "google/cloud/scheduler/internal/cloud_scheduler_option_defaults.h"
#include "google/cloud/scheduler/internal/cloud_scheduler_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace scheduler {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudSchedulerConnection::~CloudSchedulerConnection() = default;

StreamRange<google::cloud::scheduler::v1::Job>
CloudSchedulerConnection::ListJobs(
    google::cloud::scheduler::v1::ListJobsRequest request) {
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::scheduler::v1::Job>>(
      std::move(request),
      [](google::cloud::scheduler::v1::ListJobsRequest const&) {
        return StatusOr<google::cloud::scheduler::v1::ListJobsResponse>{};
      },
      [](google::cloud::scheduler::v1::ListJobsResponse const&) {
        return std::vector<google::cloud::scheduler::v1::Job>();
      });
}

StatusOr<google::cloud::scheduler::v1::Job> CloudSchedulerConnection::GetJob(
    google::cloud::scheduler::v1::GetJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::scheduler::v1::Job> CloudSchedulerConnection::CreateJob(
    google::cloud::scheduler::v1::CreateJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::scheduler::v1::Job> CloudSchedulerConnection::UpdateJob(
    google::cloud::scheduler::v1::UpdateJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status CloudSchedulerConnection::DeleteJob(
    google::cloud::scheduler::v1::DeleteJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::scheduler::v1::Job> CloudSchedulerConnection::PauseJob(
    google::cloud::scheduler::v1::PauseJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::scheduler::v1::Job> CloudSchedulerConnection::ResumeJob(
    google::cloud::scheduler::v1::ResumeJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::scheduler::v1::Job> CloudSchedulerConnection::RunJob(
    google::cloud::scheduler::v1::RunJobRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

namespace {
class CloudSchedulerConnectionImpl : public CloudSchedulerConnection {
 public:
  CloudSchedulerConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<scheduler_internal::CloudSchedulerStub> stub,
      Options const& options)
      : background_(std::move(background)),
        stub_(std::move(stub)),
        retry_policy_prototype_(
            options.get<CloudSchedulerRetryPolicyOption>()->clone()),
        backoff_policy_prototype_(
            options.get<CloudSchedulerBackoffPolicyOption>()->clone()),
        idempotency_policy_(
            options.get<CloudSchedulerConnectionIdempotencyPolicyOption>()
                ->clone()) {}

  ~CloudSchedulerConnectionImpl() override = default;

  StreamRange<google::cloud::scheduler::v1::Job> ListJobs(
      google::cloud::scheduler::v1::ListJobsRequest request) override {
    request.clear_page_token();
    auto stub = stub_;
    auto retry = std::shared_ptr<CloudSchedulerRetryPolicy const>(
        retry_policy_prototype_->clone());
    auto backoff = std::shared_ptr<BackoffPolicy const>(
        backoff_policy_prototype_->clone());
    auto idempotency = idempotency_policy_->ListJobs(request);
    char const* function_name = __func__;
    return google::cloud::internal::MakePaginationRange<
        StreamRange<google::cloud::scheduler::v1::Job>>(
        std::move(request),
        [stub, retry, backoff, idempotency, function_name](
            google::cloud::scheduler::v1::ListJobsRequest const& r) {
          return google::cloud::internal::RetryLoop(
              retry->clone(), backoff->clone(), idempotency,
              [stub](grpc::ClientContext& context,
                     google::cloud::scheduler::v1::ListJobsRequest const&
                         request) { return stub->ListJobs(context, request); },
              r, function_name);
        },
        [](google::cloud::scheduler::v1::ListJobsResponse r) {
          std::vector<google::cloud::scheduler::v1::Job> result(
              r.jobs().size());
          auto& messages = *r.mutable_jobs();
          std::move(messages.begin(), messages.end(), result.begin());
          return result;
        });
  }

  StatusOr<google::cloud::scheduler::v1::Job> GetJob(
      google::cloud::scheduler::v1::GetJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->GetJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::scheduler::v1::GetJobRequest const& request) {
          return stub_->GetJob(context, request);
        },
        request, __func__);
  }

  StatusOr<google::cloud::scheduler::v1::Job> CreateJob(
      google::cloud::scheduler::v1::CreateJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->CreateJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::scheduler::v1::CreateJobRequest const& request) {
          return stub_->CreateJob(context, request);
        },
        request, __func__);
  }

  StatusOr<google::cloud::scheduler::v1::Job> UpdateJob(
      google::cloud::scheduler::v1::UpdateJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->UpdateJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::scheduler::v1::UpdateJobRequest const& request) {
          return stub_->UpdateJob(context, request);
        },
        request, __func__);
  }

  Status DeleteJob(
      google::cloud::scheduler::v1::DeleteJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->DeleteJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::scheduler::v1::DeleteJobRequest const& request) {
          return stub_->DeleteJob(context, request);
        },
        request, __func__);
  }

  StatusOr<google::cloud::scheduler::v1::Job> PauseJob(
      google::cloud::scheduler::v1::PauseJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->PauseJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::scheduler::v1::PauseJobRequest const& request) {
          return stub_->PauseJob(context, request);
        },
        request, __func__);
  }

  StatusOr<google::cloud::scheduler::v1::Job> ResumeJob(
      google::cloud::scheduler::v1::ResumeJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->ResumeJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::scheduler::v1::ResumeJobRequest const& request) {
          return stub_->ResumeJob(context, request);
        },
        request, __func__);
  }

  StatusOr<google::cloud::scheduler::v1::Job> RunJob(
      google::cloud::scheduler::v1::RunJobRequest const& request) override {
    return google::cloud::internal::RetryLoop(
        retry_policy_prototype_->clone(), backoff_policy_prototype_->clone(),
        idempotency_policy_->RunJob(request),
        [this](grpc::ClientContext& context,
               google::cloud::scheduler::v1::RunJobRequest const& request) {
          return stub_->RunJob(context, request);
        },
        request, __func__);
  }

 private:
  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<scheduler_internal::CloudSchedulerStub> stub_;
  std::unique_ptr<CloudSchedulerRetryPolicy const> retry_policy_prototype_;
  std::unique_ptr<BackoffPolicy const> backoff_policy_prototype_;
  std::unique_ptr<CloudSchedulerConnectionIdempotencyPolicy>
      idempotency_policy_;
};
}  // namespace

std::shared_ptr<CloudSchedulerConnection> MakeCloudSchedulerConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 CloudSchedulerPolicyOptionList>(options,
                                                                 __func__);
  options =
      scheduler_internal::CloudSchedulerDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = scheduler_internal::CreateDefaultCloudSchedulerStub(
      background->cq(), options);
  return std::make_shared<CloudSchedulerConnectionImpl>(
      std::move(background), std::move(stub), options);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace scheduler
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace scheduler_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<scheduler::CloudSchedulerConnection>
MakeCloudSchedulerConnection(std::shared_ptr<CloudSchedulerStub> stub,
                             Options options) {
  options = CloudSchedulerDefaultOptions(std::move(options));
  return std::make_shared<scheduler::CloudSchedulerConnectionImpl>(
      internal::MakeBackgroundThreadsFactory(options)(), std::move(stub),
      std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace scheduler_internal
}  // namespace cloud
}  // namespace google
