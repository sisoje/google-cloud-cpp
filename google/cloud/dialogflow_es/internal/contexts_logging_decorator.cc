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
// source: google/cloud/dialogflow/v2/context.proto

#include "google/cloud/dialogflow_es/internal/contexts_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/v2/context.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ContextsLogging::ContextsLogging(std::shared_ptr<ContextsStub> child,
                                 TracingOptions tracing_options,
                                 std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::dialogflow::v2::ListContextsResponse>
ContextsLogging::ListContexts(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::ListContextsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::dialogflow::v2::ListContextsRequest const& request) {
        return child_->ListContexts(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::v2::Context> ContextsLogging::GetContext(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::GetContextRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::v2::GetContextRequest const& request) {
        return child_->GetContext(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::v2::Context> ContextsLogging::CreateContext(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::CreateContextRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::dialogflow::v2::CreateContextRequest const& request) {
        return child_->CreateContext(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::v2::Context> ContextsLogging::UpdateContext(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::UpdateContextRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::dialogflow::v2::UpdateContextRequest const& request) {
        return child_->UpdateContext(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status ContextsLogging::DeleteContext(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::DeleteContextRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::dialogflow::v2::DeleteContextRequest const& request) {
        return child_->DeleteContext(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status ContextsLogging::DeleteAllContexts(
    grpc::ClientContext& context,
    google::cloud::dialogflow::v2::DeleteAllContextsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::v2::DeleteAllContextsRequest const&
                 request) {
        return child_->DeleteAllContexts(context, request);
      },
      context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google
