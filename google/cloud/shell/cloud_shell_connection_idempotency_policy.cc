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
// source: google/cloud/shell/v1/cloudshell.proto

#include "google/cloud/shell/cloud_shell_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace shell {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

CloudShellServiceConnectionIdempotencyPolicy::
    ~CloudShellServiceConnectionIdempotencyPolicy() = default;

std::unique_ptr<CloudShellServiceConnectionIdempotencyPolicy>
CloudShellServiceConnectionIdempotencyPolicy::clone() const {
  return absl::make_unique<CloudShellServiceConnectionIdempotencyPolicy>(*this);
}

Idempotency CloudShellServiceConnectionIdempotencyPolicy::GetEnvironment(
    google::cloud::shell::v1::GetEnvironmentRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency CloudShellServiceConnectionIdempotencyPolicy::StartEnvironment(
    google::cloud::shell::v1::StartEnvironmentRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency CloudShellServiceConnectionIdempotencyPolicy::AuthorizeEnvironment(
    google::cloud::shell::v1::AuthorizeEnvironmentRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency CloudShellServiceConnectionIdempotencyPolicy::AddPublicKey(
    google::cloud::shell::v1::AddPublicKeyRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency CloudShellServiceConnectionIdempotencyPolicy::RemovePublicKey(
    google::cloud::shell::v1::RemovePublicKeyRequest const&) {
  return Idempotency::kNonIdempotent;
}

std::unique_ptr<CloudShellServiceConnectionIdempotencyPolicy>
MakeDefaultCloudShellServiceConnectionIdempotencyPolicy() {
  return absl::make_unique<CloudShellServiceConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace shell
}  // namespace cloud
}  // namespace google
