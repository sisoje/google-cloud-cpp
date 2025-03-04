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
// source: google/iam/v1/iam_policy.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_IAM_POLICY_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_IAM_POLICY_CLIENT_H

#include "google/cloud/iam/iam_policy_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace iam {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// API Overview
///
///
/// Manages Identity and Access Management (IAM) policies.
///
/// Any implementation of an API that offers access control features
/// implements the google.iam.v1.IAMPolicy interface.
///
/// ## Data model
///
/// Access control is applied when a principal (user or service account), takes
/// some action on a resource exposed by a service. Resources, identified by
/// URI-like names, are the unit of access control specification. Service
/// implementations can choose the granularity of access control and the
/// supported permissions for their resources.
/// For example one database service may allow access control to be
/// specified only at the Table level, whereas another might allow access
/// control to also be specified at the Column level.
///
/// ## Policy Structure
///
/// See google.iam.v1.Policy
///
/// This is intentionally not a CRUD style API because access control policies
/// are created and deleted implicitly with the resources to which they are
/// attached.
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class IAMPolicyClient {
 public:
  explicit IAMPolicyClient(std::shared_ptr<IAMPolicyConnection> connection,
                           Options opts = {});
  ~IAMPolicyClient();

  ///@{
  // @name Copy and move support
  IAMPolicyClient(IAMPolicyClient const&) = default;
  IAMPolicyClient& operator=(IAMPolicyClient const&) = default;
  IAMPolicyClient(IAMPolicyClient&&) = default;
  IAMPolicyClient& operator=(IAMPolicyClient&&) = default;
  ///@}

  ///@{
  // @name Equality
  friend bool operator==(IAMPolicyClient const& a, IAMPolicyClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(IAMPolicyClient const& a, IAMPolicyClient const& b) {
    return !(a == b);
  }
  ///@}

  ///
  /// Sets the access control policy on the specified resource. Replaces any
  /// existing policy.
  ///
  /// Can return `NOT_FOUND`, `INVALID_ARGUMENT`, and `PERMISSION_DENIED`
  /// errors.
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::SetIamPolicyRequest,google/iam/v1/iam_policy.proto#L101}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::iam::v1::Policy,google/iam/v1/policy.proto#L96}
  ///
  /// [google.iam.v1.SetIamPolicyRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L101}
  /// [google.iam.v1.Policy]:
  /// @googleapis_reference_link{google/iam/v1/policy.proto#L96}
  ///
  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const& request, Options opts = {});

  ///
  /// Gets the access control policy for a resource.
  /// Returns an empty policy if the resource exists and does not have a policy
  /// set.
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::GetIamPolicyRequest,google/iam/v1/iam_policy.proto#L123}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::iam::v1::Policy,google/iam/v1/policy.proto#L96}
  ///
  /// [google.iam.v1.GetIamPolicyRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L123}
  /// [google.iam.v1.Policy]:
  /// @googleapis_reference_link{google/iam/v1/policy.proto#L96}
  ///
  StatusOr<google::iam::v1::Policy> GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const& request, Options opts = {});

  ///
  /// Returns permissions that a caller has on the specified resource.
  /// If the resource does not exist, this will return an empty set of
  /// permissions, not a `NOT_FOUND` error.
  ///
  /// Note: This operation is designed to be used for building permission-aware
  /// UIs and command-line tools, not for authorization checking. This operation
  /// may "fail open" without warning.
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::TestIamPermissionsRequest,google/iam/v1/iam_policy.proto#L136}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::iam::v1::TestIamPermissionsResponse,google/iam/v1/iam_policy.proto#L151}
  ///
  /// [google.iam.v1.TestIamPermissionsRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L136}
  /// [google.iam.v1.TestIamPermissionsResponse]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L151}
  ///
  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      google::iam::v1::TestIamPermissionsRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<IAMPolicyConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace iam
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_IAM_POLICY_CLIENT_H
