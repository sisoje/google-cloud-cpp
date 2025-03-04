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
// source: google/cloud/notebooks/v1/managed_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_MANAGED_NOTEBOOK_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_MANAGED_NOTEBOOK_CLIENT_H

#include "google/cloud/notebooks/managed_notebook_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace notebooks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// API v1 service for Managed Notebooks.
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
class ManagedNotebookServiceClient {
 public:
  explicit ManagedNotebookServiceClient(
      std::shared_ptr<ManagedNotebookServiceConnection> connection,
      Options opts = {});
  ~ManagedNotebookServiceClient();

  ///@{
  // @name Copy and move support
  ManagedNotebookServiceClient(ManagedNotebookServiceClient const&) = default;
  ManagedNotebookServiceClient& operator=(ManagedNotebookServiceClient const&) =
      default;
  ManagedNotebookServiceClient(ManagedNotebookServiceClient&&) = default;
  ManagedNotebookServiceClient& operator=(ManagedNotebookServiceClient&&) =
      default;
  ///@}

  ///@{
  // @name Equality
  friend bool operator==(ManagedNotebookServiceClient const& a,
                         ManagedNotebookServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(ManagedNotebookServiceClient const& a,
                         ManagedNotebookServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  ///
  /// Lists Runtimes in a given project and location.
  ///
  /// @param parent  Required. Format:
  ///  `parent=projects/{project_id}/locations/{location}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.ListRuntimesRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L209}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  StreamRange<google::cloud::notebooks::v1::Runtime> ListRuntimes(
      std::string const& parent, Options opts = {});

  ///
  /// Lists Runtimes in a given project and location.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::ListRuntimesRequest,google/cloud/notebooks/v1/managed_service.proto#L209}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.ListRuntimesRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L209}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  StreamRange<google::cloud::notebooks::v1::Runtime> ListRuntimes(
      google::cloud::notebooks::v1::ListRuntimesRequest request,
      Options opts = {});

  ///
  /// Gets details of a single Runtime. The location must be a regional endpoint
  /// rather than zonal.
  ///
  /// @param name  Required. Format:
  ///  `projects/{project_id}/locations/{location}/runtimes/{runtime_id}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.GetRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L243}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  StatusOr<google::cloud::notebooks::v1::Runtime> GetRuntime(
      std::string const& name, Options opts = {});

  ///
  /// Gets details of a single Runtime. The location must be a regional endpoint
  /// rather than zonal.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::GetRuntimeRequest,google/cloud/notebooks/v1/managed_service.proto#L243}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.GetRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L243}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  StatusOr<google::cloud::notebooks::v1::Runtime> GetRuntime(
      google::cloud::notebooks::v1::GetRuntimeRequest const& request,
      Options opts = {});

  ///
  /// Creates a new Runtime in a given project and location.
  ///
  /// @param parent  Required. Format:
  ///  `parent=projects/{project_id}/locations/{location}`
  /// @param runtime_id  Required. User-defined unique ID of this Runtime.
  /// @param runtime  Required. The Runtime to be created.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.CreateRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L255}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> CreateRuntime(
      std::string const& parent, std::string const& runtime_id,
      google::cloud::notebooks::v1::Runtime const& runtime, Options opts = {});

  ///
  /// Creates a new Runtime in a given project and location.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::CreateRuntimeRequest,google/cloud/notebooks/v1/managed_service.proto#L255}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.CreateRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L255}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> CreateRuntime(
      google::cloud::notebooks::v1::CreateRuntimeRequest const& request,
      Options opts = {});

  ///
  /// Update Notebook Runtime configuration.
  ///
  /// @param runtime  Required. The Runtime to be updated.
  /// @param update_mask  Required. Specifies the path, relative to `Runtime`,
  /// of
  ///  the field to update. For example, to change the software configuration
  ///  kernels, the `update_mask` parameter would be
  ///  specified as `software_config.kernels`,
  ///  and the `PATCH` request body would specify the new value, as follows:
  ///      {
  ///        "software_config":{
  ///          "kernels": [{
  ///             'repository':
  ///             'gcr.io/deeplearning-platform-release/pytorch-gpu', 'tag':
  ///             'latest' }],
  ///          }
  ///      }
  ///
  ///  Currently, only the following fields can be updated:
  ///  - software_config.kernels
  ///  - software_config.post_startup_script
  ///  - software_config.custom_gpu_driver_path
  ///  - software_config.idle_shutdown
  ///  - software_config.idle_shutdown_timeout
  ///  - software_config.disable_terminal
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.UpdateRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L368}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> UpdateRuntime(
      google::cloud::notebooks::v1::Runtime const& runtime,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  ///
  /// Update Notebook Runtime configuration.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::UpdateRuntimeRequest,google/cloud/notebooks/v1/managed_service.proto#L368}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.UpdateRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L368}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> UpdateRuntime(
      google::cloud::notebooks::v1::UpdateRuntimeRequest const& request,
      Options opts = {});

  ///
  /// Deletes a single Runtime.
  ///
  /// @param name  Required. Format:
  ///  `projects/{project_id}/locations/{location}/runtimes/{runtime_id}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::OperationMetadata,google/cloud/notebooks/v1/service.proto#L422}
  ///
  /// [google.cloud.notebooks.v1.DeleteRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L276}
  /// [google.cloud.notebooks.v1.OperationMetadata]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/service.proto#L422}
  ///
  future<StatusOr<google::cloud::notebooks::v1::OperationMetadata>>
  DeleteRuntime(std::string const& name, Options opts = {});

  ///
  /// Deletes a single Runtime.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::DeleteRuntimeRequest,google/cloud/notebooks/v1/managed_service.proto#L276}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::OperationMetadata,google/cloud/notebooks/v1/service.proto#L422}
  ///
  /// [google.cloud.notebooks.v1.DeleteRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L276}
  /// [google.cloud.notebooks.v1.OperationMetadata]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/service.proto#L422}
  ///
  future<StatusOr<google::cloud::notebooks::v1::OperationMetadata>>
  DeleteRuntime(
      google::cloud::notebooks::v1::DeleteRuntimeRequest const& request,
      Options opts = {});

  ///
  /// Starts a Managed Notebook Runtime.
  /// Perform "Start" on GPU instances; "Resume" on CPU instances
  /// See:
  /// https://cloud.google.com/compute/docs/instances/stop-start-instance
  /// https://cloud.google.com/compute/docs/instances/suspend-resume-instance
  ///
  /// @param name  Required. Format:
  ///  `projects/{project_id}/locations/{location}/runtimes/{runtime_id}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.StartRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L291}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> StartRuntime(
      std::string const& name, Options opts = {});

  ///
  /// Starts a Managed Notebook Runtime.
  /// Perform "Start" on GPU instances; "Resume" on CPU instances
  /// See:
  /// https://cloud.google.com/compute/docs/instances/stop-start-instance
  /// https://cloud.google.com/compute/docs/instances/suspend-resume-instance
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::StartRuntimeRequest,google/cloud/notebooks/v1/managed_service.proto#L291}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.StartRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L291}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> StartRuntime(
      google::cloud::notebooks::v1::StartRuntimeRequest const& request,
      Options opts = {});

  ///
  /// Stops a Managed Notebook Runtime.
  /// Perform "Stop" on GPU instances; "Suspend" on CPU instances
  /// See:
  /// https://cloud.google.com/compute/docs/instances/stop-start-instance
  /// https://cloud.google.com/compute/docs/instances/suspend-resume-instance
  ///
  /// @param name  Required. Format:
  ///  `projects/{project_id}/locations/{location}/runtimes/{runtime_id}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.StopRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L301}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> StopRuntime(
      std::string const& name, Options opts = {});

  ///
  /// Stops a Managed Notebook Runtime.
  /// Perform "Stop" on GPU instances; "Suspend" on CPU instances
  /// See:
  /// https://cloud.google.com/compute/docs/instances/stop-start-instance
  /// https://cloud.google.com/compute/docs/instances/suspend-resume-instance
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::StopRuntimeRequest,google/cloud/notebooks/v1/managed_service.proto#L301}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.StopRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L301}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> StopRuntime(
      google::cloud::notebooks::v1::StopRuntimeRequest const& request,
      Options opts = {});

  ///
  /// Switch a Managed Notebook Runtime.
  ///
  /// @param name  Required. Format:
  ///  `projects/{project_id}/locations/{location}/runtimes/{runtime_id}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.SwitchRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L311}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> SwitchRuntime(
      std::string const& name, Options opts = {});

  ///
  /// Switch a Managed Notebook Runtime.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::SwitchRuntimeRequest,google/cloud/notebooks/v1/managed_service.proto#L311}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.SwitchRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L311}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> SwitchRuntime(
      google::cloud::notebooks::v1::SwitchRuntimeRequest const& request,
      Options opts = {});

  ///
  /// Resets a Managed Notebook Runtime.
  ///
  /// @param name  Required. Format:
  ///  `projects/{project_id}/locations/{location}/runtimes/{runtime_id}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.ResetRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L327}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> ResetRuntime(
      std::string const& name, Options opts = {});

  ///
  /// Resets a Managed Notebook Runtime.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::ResetRuntimeRequest,google/cloud/notebooks/v1/managed_service.proto#L327}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.ResetRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L327}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> ResetRuntime(
      google::cloud::notebooks::v1::ResetRuntimeRequest const& request,
      Options opts = {});

  ///
  /// Upgrades a Managed Notebook Runtime to the latest version.
  ///
  /// @param name  Required. Format:
  ///  `projects/{project_id}/locations/{location}/runtimes/{runtime_id}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.UpgradeRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L339}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> UpgradeRuntime(
      std::string const& name, Options opts = {});

  ///
  /// Upgrades a Managed Notebook Runtime to the latest version.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::UpgradeRuntimeRequest,google/cloud/notebooks/v1/managed_service.proto#L339}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.UpgradeRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L339}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> UpgradeRuntime(
      google::cloud::notebooks::v1::UpgradeRuntimeRequest const& request,
      Options opts = {});

  ///
  /// Report and process a runtime event.
  ///
  /// @param name  Required. Format:
  ///  `projects/{project_id}/locations/{location}/runtimes/{runtime_id}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.ReportRuntimeEventRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L349}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> ReportRuntimeEvent(
      std::string const& name, Options opts = {});

  ///
  /// Report and process a runtime event.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::ReportRuntimeEventRequest,google/cloud/notebooks/v1/managed_service.proto#L349}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.ReportRuntimeEventRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L349}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> ReportRuntimeEvent(
      google::cloud::notebooks::v1::ReportRuntimeEventRequest const& request,
      Options opts = {});

  ///
  /// Gets an access token for the consumer service account that the customer
  /// attached to the runtime. Only accessible from the tenant instance.
  ///
  /// @param name  Required. Format:
  ///  `projects/{project_id}/locations/{location}/runtimes/{runtime_id}`
  /// @param vm_id  Required. The VM hardware token for authenticating the VM.
  ///  https://cloud.google.com/compute/docs/instances/verifying-instance-identity
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::RefreshRuntimeTokenInternalResponse,google/cloud/notebooks/v1/managed_service.proto#L418}
  ///
  /// [google.cloud.notebooks.v1.RefreshRuntimeTokenInternalRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L402}
  /// [google.cloud.notebooks.v1.RefreshRuntimeTokenInternalResponse]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L418}
  ///
  StatusOr<google::cloud::notebooks::v1::RefreshRuntimeTokenInternalResponse>
  RefreshRuntimeTokenInternal(std::string const& name, std::string const& vm_id,
                              Options opts = {});

  ///
  /// Gets an access token for the consumer service account that the customer
  /// attached to the runtime. Only accessible from the tenant instance.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::RefreshRuntimeTokenInternalRequest,google/cloud/notebooks/v1/managed_service.proto#L402}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::RefreshRuntimeTokenInternalResponse,google/cloud/notebooks/v1/managed_service.proto#L418}
  ///
  /// [google.cloud.notebooks.v1.RefreshRuntimeTokenInternalRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L402}
  /// [google.cloud.notebooks.v1.RefreshRuntimeTokenInternalResponse]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L418}
  ///
  StatusOr<google::cloud::notebooks::v1::RefreshRuntimeTokenInternalResponse>
  RefreshRuntimeTokenInternal(
      google::cloud::notebooks::v1::RefreshRuntimeTokenInternalRequest const&
          request,
      Options opts = {});

  ///
  /// Creates a Diagnostic File and runs Diagnostic Tool given a Runtime.
  ///
  /// @param name  Required. Format:
  ///  `projects/{project_id}/locations/{location}/runtimes/{runtimes_id}`
  /// @param diagnostic_config  Required. Defines flags that are used to run the
  /// diagnostic tool
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.DiagnoseRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L427}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> DiagnoseRuntime(
      std::string const& name,
      google::cloud::notebooks::v1::DiagnosticConfig const& diagnostic_config,
      Options opts = {});

  ///
  /// Creates a Diagnostic File and runs Diagnostic Tool given a Runtime.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::notebooks::v1::DiagnoseRuntimeRequest,google/cloud/notebooks/v1/managed_service.proto#L427}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::notebooks::v1::Runtime,google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  /// [google.cloud.notebooks.v1.DiagnoseRuntimeRequest]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/managed_service.proto#L427}
  /// [google.cloud.notebooks.v1.Runtime]:
  /// @googleapis_reference_link{google/cloud/notebooks/v1/runtime.proto#L33}
  ///
  future<StatusOr<google::cloud::notebooks::v1::Runtime>> DiagnoseRuntime(
      google::cloud::notebooks::v1::DiagnoseRuntimeRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<ManagedNotebookServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace notebooks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_MANAGED_NOTEBOOK_CLIENT_H
