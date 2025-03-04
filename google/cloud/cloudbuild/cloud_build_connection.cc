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
// source: google/devtools/cloudbuild/v1/cloudbuild.proto

#include "google/cloud/cloudbuild/cloud_build_connection.h"
#include "google/cloud/cloudbuild/cloud_build_options.h"
#include "google/cloud/cloudbuild/internal/cloud_build_connection_impl.h"
#include "google/cloud/cloudbuild/internal/cloud_build_option_defaults.h"
#include "google/cloud/cloudbuild/internal/cloud_build_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace cloudbuild {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudBuildConnection::~CloudBuildConnection() = default;

future<StatusOr<google::devtools::cloudbuild::v1::Build>>
CloudBuildConnection::CreateBuild(
    google::devtools::cloudbuild::v1::CreateBuildRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v1::Build>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::devtools::cloudbuild::v1::Build>
CloudBuildConnection::GetBuild(
    google::devtools::cloudbuild::v1::GetBuildRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::devtools::cloudbuild::v1::Build>
CloudBuildConnection::ListBuilds(
    google::devtools::cloudbuild::v1::
        ListBuildsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::devtools::cloudbuild::v1::Build>>();
}

StatusOr<google::devtools::cloudbuild::v1::Build>
CloudBuildConnection::CancelBuild(
    google::devtools::cloudbuild::v1::CancelBuildRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::devtools::cloudbuild::v1::Build>>
CloudBuildConnection::RetryBuild(
    google::devtools::cloudbuild::v1::RetryBuildRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v1::Build>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::devtools::cloudbuild::v1::Build>>
CloudBuildConnection::ApproveBuild(
    google::devtools::cloudbuild::v1::ApproveBuildRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v1::Build>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::devtools::cloudbuild::v1::BuildTrigger>
CloudBuildConnection::CreateBuildTrigger(
    google::devtools::cloudbuild::v1::CreateBuildTriggerRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::devtools::cloudbuild::v1::BuildTrigger>
CloudBuildConnection::GetBuildTrigger(
    google::devtools::cloudbuild::v1::GetBuildTriggerRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::devtools::cloudbuild::v1::BuildTrigger>
CloudBuildConnection::ListBuildTriggers(
    google::devtools::cloudbuild::v1::
        ListBuildTriggersRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::devtools::cloudbuild::v1::BuildTrigger>>();
}

Status CloudBuildConnection::DeleteBuildTrigger(
    google::devtools::cloudbuild::v1::DeleteBuildTriggerRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::devtools::cloudbuild::v1::BuildTrigger>
CloudBuildConnection::UpdateBuildTrigger(
    google::devtools::cloudbuild::v1::UpdateBuildTriggerRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::devtools::cloudbuild::v1::Build>>
CloudBuildConnection::RunBuildTrigger(
    google::devtools::cloudbuild::v1::RunBuildTriggerRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v1::Build>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::devtools::cloudbuild::v1::ReceiveTriggerWebhookResponse>
CloudBuildConnection::ReceiveTriggerWebhook(
    google::devtools::cloudbuild::v1::ReceiveTriggerWebhookRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<google::devtools::cloudbuild::v1::WorkerPool>>
CloudBuildConnection::CreateWorkerPool(
    google::devtools::cloudbuild::v1::CreateWorkerPoolRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v1::WorkerPool>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::devtools::cloudbuild::v1::WorkerPool>
CloudBuildConnection::GetWorkerPool(
    google::devtools::cloudbuild::v1::GetWorkerPoolRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

future<StatusOr<
    google::devtools::cloudbuild::v1::DeleteWorkerPoolOperationMetadata>>
CloudBuildConnection::DeleteWorkerPool(
    google::devtools::cloudbuild::v1::DeleteWorkerPoolRequest const&) {
  return google::cloud::make_ready_future<StatusOr<
      google::devtools::cloudbuild::v1::DeleteWorkerPoolOperationMetadata>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::devtools::cloudbuild::v1::WorkerPool>>
CloudBuildConnection::UpdateWorkerPool(
    google::devtools::cloudbuild::v1::UpdateWorkerPoolRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v1::WorkerPool>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StreamRange<google::devtools::cloudbuild::v1::WorkerPool>
CloudBuildConnection::ListWorkerPools(
    google::devtools::cloudbuild::v1::
        ListWorkerPoolsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::devtools::cloudbuild::v1::WorkerPool>>();
}

std::shared_ptr<CloudBuildConnection> MakeCloudBuildConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UnifiedCredentialsOptionList,
                                 CloudBuildPolicyOptionList>(options, __func__);
  options = cloudbuild_internal::CloudBuildDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = cloudbuild_internal::CreateDefaultCloudBuildStub(background->cq(),
                                                               options);
  return std::make_shared<cloudbuild_internal::CloudBuildConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloudbuild
}  // namespace cloud
}  // namespace google
