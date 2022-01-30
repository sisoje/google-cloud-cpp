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

#include "google/cloud/monitoring/notification_channel_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

NotificationChannelServiceConnectionIdempotencyPolicy::
    ~NotificationChannelServiceConnectionIdempotencyPolicy() = default;

namespace {
class DefaultNotificationChannelServiceConnectionIdempotencyPolicy
    : public NotificationChannelServiceConnectionIdempotencyPolicy {
 public:
  ~DefaultNotificationChannelServiceConnectionIdempotencyPolicy() override =
      default;

  /// Create a new copy of this object.
  std::unique_ptr<NotificationChannelServiceConnectionIdempotencyPolicy> clone()
      const override {
    return absl::make_unique<
        DefaultNotificationChannelServiceConnectionIdempotencyPolicy>(*this);
  }

  Idempotency ListNotificationChannelDescriptors(
      google::monitoring::v3::ListNotificationChannelDescriptorsRequest)
      override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetNotificationChannelDescriptor(
      google::monitoring::v3::GetNotificationChannelDescriptorRequest const&)
      override {
    return Idempotency::kIdempotent;
  }

  Idempotency ListNotificationChannels(
      google::monitoring::v3::ListNotificationChannelsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetNotificationChannel(
      google::monitoring::v3::GetNotificationChannelRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency CreateNotificationChannel(
      google::monitoring::v3::CreateNotificationChannelRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency UpdateNotificationChannel(
      google::monitoring::v3::UpdateNotificationChannelRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteNotificationChannel(
      google::monitoring::v3::DeleteNotificationChannelRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency SendNotificationChannelVerificationCode(
      google::monitoring::v3::
          SendNotificationChannelVerificationCodeRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency GetNotificationChannelVerificationCode(
      google::monitoring::v3::
          GetNotificationChannelVerificationCodeRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency VerifyNotificationChannel(
      google::monitoring::v3::VerifyNotificationChannelRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }
};
}  // namespace

std::unique_ptr<NotificationChannelServiceConnectionIdempotencyPolicy>
MakeDefaultNotificationChannelServiceConnectionIdempotencyPolicy() {
  return absl::make_unique<
      DefaultNotificationChannelServiceConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring
}  // namespace cloud
}  // namespace google
