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
// source: google/monitoring/v3/notification_service.proto

#include "google/cloud/monitoring/internal/notification_channel_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/monitoring/v3/notification_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

NotificationChannelServiceStub::~NotificationChannelServiceStub() = default;

StatusOr<google::monitoring::v3::ListNotificationChannelDescriptorsResponse>
DefaultNotificationChannelServiceStub::ListNotificationChannelDescriptors(
    grpc::ClientContext& client_context,
    google::monitoring::v3::ListNotificationChannelDescriptorsRequest const&
        request) {
  google::monitoring::v3::ListNotificationChannelDescriptorsResponse response;
  auto status = grpc_stub_->ListNotificationChannelDescriptors(
      &client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::monitoring::v3::NotificationChannelDescriptor>
DefaultNotificationChannelServiceStub::GetNotificationChannelDescriptor(
    grpc::ClientContext& client_context,
    google::monitoring::v3::GetNotificationChannelDescriptorRequest const&
        request) {
  google::monitoring::v3::NotificationChannelDescriptor response;
  auto status = grpc_stub_->GetNotificationChannelDescriptor(
      &client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::monitoring::v3::ListNotificationChannelsResponse>
DefaultNotificationChannelServiceStub::ListNotificationChannels(
    grpc::ClientContext& client_context,
    google::monitoring::v3::ListNotificationChannelsRequest const& request) {
  google::monitoring::v3::ListNotificationChannelsResponse response;
  auto status =
      grpc_stub_->ListNotificationChannels(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::monitoring::v3::NotificationChannel>
DefaultNotificationChannelServiceStub::GetNotificationChannel(
    grpc::ClientContext& client_context,
    google::monitoring::v3::GetNotificationChannelRequest const& request) {
  google::monitoring::v3::NotificationChannel response;
  auto status =
      grpc_stub_->GetNotificationChannel(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::monitoring::v3::NotificationChannel>
DefaultNotificationChannelServiceStub::CreateNotificationChannel(
    grpc::ClientContext& client_context,
    google::monitoring::v3::CreateNotificationChannelRequest const& request) {
  google::monitoring::v3::NotificationChannel response;
  auto status = grpc_stub_->CreateNotificationChannel(&client_context, request,
                                                      &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::monitoring::v3::NotificationChannel>
DefaultNotificationChannelServiceStub::UpdateNotificationChannel(
    grpc::ClientContext& client_context,
    google::monitoring::v3::UpdateNotificationChannelRequest const& request) {
  google::monitoring::v3::NotificationChannel response;
  auto status = grpc_stub_->UpdateNotificationChannel(&client_context, request,
                                                      &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

Status DefaultNotificationChannelServiceStub::DeleteNotificationChannel(
    grpc::ClientContext& client_context,
    google::monitoring::v3::DeleteNotificationChannelRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->DeleteNotificationChannel(&client_context, request,
                                                      &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

Status
DefaultNotificationChannelServiceStub::SendNotificationChannelVerificationCode(
    grpc::ClientContext& client_context,
    google::monitoring::v3::
        SendNotificationChannelVerificationCodeRequest const& request) {
  google::protobuf::Empty response;
  auto status = grpc_stub_->SendNotificationChannelVerificationCode(
      &client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

StatusOr<google::monitoring::v3::GetNotificationChannelVerificationCodeResponse>
DefaultNotificationChannelServiceStub::GetNotificationChannelVerificationCode(
    grpc::ClientContext& client_context,
    google::monitoring::v3::GetNotificationChannelVerificationCodeRequest const&
        request) {
  google::monitoring::v3::GetNotificationChannelVerificationCodeResponse
      response;
  auto status = grpc_stub_->GetNotificationChannelVerificationCode(
      &client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::monitoring::v3::NotificationChannel>
DefaultNotificationChannelServiceStub::VerifyNotificationChannel(
    grpc::ClientContext& client_context,
    google::monitoring::v3::VerifyNotificationChannelRequest const& request) {
  google::monitoring::v3::NotificationChannel response;
  auto status = grpc_stub_->VerifyNotificationChannel(&client_context, request,
                                                      &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google
