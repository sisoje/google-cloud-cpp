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
// source: google/cloud/dialogflow/cx/v3/flow.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_FLOWS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_FLOWS_CLIENT_H

#include "google/cloud/dialogflow_cx/flows_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service for managing [Flows][google.cloud.dialogflow.cx.v3.Flow].
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
class FlowsClient {
 public:
  explicit FlowsClient(std::shared_ptr<FlowsConnection> connection,
                       Options opts = {});
  ~FlowsClient();

  ///@{
  // @name Copy and move support
  FlowsClient(FlowsClient const&) = default;
  FlowsClient& operator=(FlowsClient const&) = default;
  FlowsClient(FlowsClient&&) = default;
  FlowsClient& operator=(FlowsClient&&) = default;
  ///@}

  ///@{
  // @name Equality
  friend bool operator==(FlowsClient const& a, FlowsClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(FlowsClient const& a, FlowsClient const& b) {
    return !(a == b);
  }
  ///@}

  ///
  /// Creates a flow in the specified agent.
  ///
  /// Note: You should always train a flow prior to sending it queries. See the
  /// [training
  /// documentation](https://cloud.google.com/dialogflow/cx/docs/concept/training).
  ///
  /// @param parent  Required. The agent to create a flow for.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>`.
  /// @param flow  Required. The flow to create.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::Flow,google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  /// [google.cloud.dialogflow.cx.v3.CreateFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L316}
  /// [google.cloud.dialogflow.cx.v3.Flow]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::Flow> CreateFlow(
      std::string const& parent,
      google::cloud::dialogflow::cx::v3::Flow const& flow, Options opts = {});

  ///
  /// Creates a flow in the specified agent.
  ///
  /// Note: You should always train a flow prior to sending it queries. See the
  /// [training
  /// documentation](https://cloud.google.com/dialogflow/cx/docs/concept/training).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::CreateFlowRequest,google/cloud/dialogflow/cx/v3/flow.proto#L316}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::Flow,google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  /// [google.cloud.dialogflow.cx.v3.CreateFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L316}
  /// [google.cloud.dialogflow.cx.v3.Flow]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::Flow> CreateFlow(
      google::cloud::dialogflow::cx::v3::CreateFlowRequest const& request,
      Options opts = {});

  ///
  /// Deletes a specified flow.
  ///
  /// @param name  Required. The name of the flow to delete.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/flows/<Flow ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
  /// [google.cloud.dialogflow.cx.v3.DeleteFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L345}
  ///
  Status DeleteFlow(std::string const& name, Options opts = {});

  ///
  /// Deletes a specified flow.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::DeleteFlowRequest,google/cloud/dialogflow/cx/v3/flow.proto#L345}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
  /// [google.cloud.dialogflow.cx.v3.DeleteFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L345}
  ///
  Status DeleteFlow(
      google::cloud::dialogflow::cx::v3::DeleteFlowRequest const& request,
      Options opts = {});

  ///
  /// Returns the list of all flows in the specified agent.
  ///
  /// @param parent  Required. The agent containing the flows.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::Flow,google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  /// [google.cloud.dialogflow.cx.v3.ListFlowsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L370}
  /// [google.cloud.dialogflow.cx.v3.Flow]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  StreamRange<google::cloud::dialogflow::cx::v3::Flow> ListFlows(
      std::string const& parent, Options opts = {});

  ///
  /// Returns the list of all flows in the specified agent.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ListFlowsRequest,google/cloud/dialogflow/cx/v3/flow.proto#L370}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::Flow,google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  /// [google.cloud.dialogflow.cx.v3.ListFlowsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L370}
  /// [google.cloud.dialogflow.cx.v3.Flow]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  StreamRange<google::cloud::dialogflow::cx::v3::Flow> ListFlows(
      google::cloud::dialogflow::cx::v3::ListFlowsRequest request,
      Options opts = {});

  ///
  /// Retrieves the specified flow.
  ///
  /// @param name  Required. The name of the flow to get.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/flows/<Flow ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::Flow,google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  /// [google.cloud.dialogflow.cx.v3.GetFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L415}
  /// [google.cloud.dialogflow.cx.v3.Flow]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::Flow> GetFlow(
      std::string const& name, Options opts = {});

  ///
  /// Retrieves the specified flow.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::GetFlowRequest,google/cloud/dialogflow/cx/v3/flow.proto#L415}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::Flow,google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  /// [google.cloud.dialogflow.cx.v3.GetFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L415}
  /// [google.cloud.dialogflow.cx.v3.Flow]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::Flow> GetFlow(
      google::cloud::dialogflow::cx::v3::GetFlowRequest const& request,
      Options opts = {});

  ///
  /// Updates the specified flow.
  ///
  /// Note: You should always train a flow prior to sending it queries. See the
  /// [training
  /// documentation](https://cloud.google.com/dialogflow/cx/docs/concept/training).
  ///
  /// @param flow  Required. The flow to update.
  /// @param update_mask  The mask to control which fields get updated. If the
  /// mask is not present,
  ///  all fields will be updated.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::Flow,google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  /// [google.cloud.dialogflow.cx.v3.UpdateFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L443}
  /// [google.cloud.dialogflow.cx.v3.Flow]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::Flow> UpdateFlow(
      google::cloud::dialogflow::cx::v3::Flow const& flow,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  ///
  /// Updates the specified flow.
  ///
  /// Note: You should always train a flow prior to sending it queries. See the
  /// [training
  /// documentation](https://cloud.google.com/dialogflow/cx/docs/concept/training).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::UpdateFlowRequest,google/cloud/dialogflow/cx/v3/flow.proto#L443}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::Flow,google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  /// [google.cloud.dialogflow.cx.v3.UpdateFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L443}
  /// [google.cloud.dialogflow.cx.v3.Flow]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L247}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::Flow> UpdateFlow(
      google::cloud::dialogflow::cx::v3::UpdateFlowRequest const& request,
      Options opts = {});

  ///
  /// Trains the specified flow. Note that only the flow in 'draft' environment
  /// is trained.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/cx/docs/how/long-running-operation).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`: An empty [Struct
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#struct)
  /// - `response`: An [Empty
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#empty)
  ///
  /// Note: You should always train a flow prior to sending it queries. See the
  /// [training
  /// documentation](https://cloud.google.com/dialogflow/cx/docs/concept/training).
  ///
  /// @param name  Required. The flow to train.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/flows/<Flow ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::protobuf::Struct,google/protobuf/struct.proto#L51}
  ///
  /// [google.cloud.dialogflow.cx.v3.TrainFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L467}
  /// [google.protobuf.Struct]:
  /// @googleapis_reference_link{google/protobuf/struct.proto#L51}
  ///
  future<StatusOr<google::protobuf::Struct>> TrainFlow(std::string const& name,
                                                       Options opts = {});

  ///
  /// Trains the specified flow. Note that only the flow in 'draft' environment
  /// is trained.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/cx/docs/how/long-running-operation).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`: An empty [Struct
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#struct)
  /// - `response`: An [Empty
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#empty)
  ///
  /// Note: You should always train a flow prior to sending it queries. See the
  /// [training
  /// documentation](https://cloud.google.com/dialogflow/cx/docs/concept/training).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TrainFlowRequest,google/cloud/dialogflow/cx/v3/flow.proto#L467}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::protobuf::Struct,google/protobuf/struct.proto#L51}
  ///
  /// [google.cloud.dialogflow.cx.v3.TrainFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L467}
  /// [google.protobuf.Struct]:
  /// @googleapis_reference_link{google/protobuf/struct.proto#L51}
  ///
  future<StatusOr<google::protobuf::Struct>> TrainFlow(
      google::cloud::dialogflow::cx::v3::TrainFlowRequest const& request,
      Options opts = {});

  ///
  /// Validates the specified flow and creates or updates validation results.
  /// Please call this API after the training is completed to get the complete
  /// validation results.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ValidateFlowRequest,google/cloud/dialogflow/cx/v3/flow.proto#L480}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::FlowValidationResult,google/cloud/dialogflow/cx/v3/flow.proto#L512}
  ///
  /// [google.cloud.dialogflow.cx.v3.ValidateFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L480}
  /// [google.cloud.dialogflow.cx.v3.FlowValidationResult]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L512}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::FlowValidationResult>
  ValidateFlow(
      google::cloud::dialogflow::cx::v3::ValidateFlowRequest const& request,
      Options opts = {});

  ///
  /// Gets the latest flow validation result. Flow validation is performed
  /// when ValidateFlow is called.
  ///
  /// @param name  Required. The flow name.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/flows/<Flow ID>/validationResult`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::FlowValidationResult,google/cloud/dialogflow/cx/v3/flow.proto#L512}
  ///
  /// [google.cloud.dialogflow.cx.v3.GetFlowValidationResultRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L496}
  /// [google.cloud.dialogflow.cx.v3.FlowValidationResult]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L512}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::FlowValidationResult>
  GetFlowValidationResult(std::string const& name, Options opts = {});

  ///
  /// Gets the latest flow validation result. Flow validation is performed
  /// when ValidateFlow is called.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::GetFlowValidationResultRequest,google/cloud/dialogflow/cx/v3/flow.proto#L496}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::FlowValidationResult,google/cloud/dialogflow/cx/v3/flow.proto#L512}
  ///
  /// [google.cloud.dialogflow.cx.v3.GetFlowValidationResultRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L496}
  /// [google.cloud.dialogflow.cx.v3.FlowValidationResult]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L512}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::FlowValidationResult>
  GetFlowValidationResult(
      google::cloud::dialogflow::cx::v3::GetFlowValidationResultRequest const&
          request,
      Options opts = {});

  ///
  /// Imports the specified flow to the specified agent from a binary file.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/cx/docs/how/long-running-operation).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`: An empty [Struct
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#struct)
  /// - `response`:
  /// [ImportFlowResponse][google.cloud.dialogflow.cx.v3.ImportFlowResponse]
  ///
  /// Note: You should always train a flow prior to sending it queries. See the
  /// [training
  /// documentation](https://cloud.google.com/dialogflow/cx/docs/concept/training).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ImportFlowRequest,google/cloud/dialogflow/cx/v3/flow.proto#L531}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ImportFlowResponse,google/cloud/dialogflow/cx/v3/flow.proto#L579}
  ///
  /// [google.cloud.dialogflow.cx.v3.ImportFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L531}
  /// [google.cloud.dialogflow.cx.v3.ImportFlowResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L579}
  ///
  future<StatusOr<google::cloud::dialogflow::cx::v3::ImportFlowResponse>>
  ImportFlow(
      google::cloud::dialogflow::cx::v3::ImportFlowRequest const& request,
      Options opts = {});

  ///
  /// Exports the specified flow to a binary file.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/cx/docs/how/long-running-operation).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`: An empty [Struct
  ///   message](https://developers.google.com/protocol-buffers/docs/reference/google.protobuf#struct)
  /// - `response`:
  /// [ExportFlowResponse][google.cloud.dialogflow.cx.v3.ExportFlowResponse]
  ///
  /// Note that resources (e.g. intents, entities, webhooks) that the flow
  /// references will also be exported.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ExportFlowRequest,google/cloud/dialogflow/cx/v3/flow.proto#L589}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ExportFlowResponse,google/cloud/dialogflow/cx/v3/flow.proto#L617}
  ///
  /// [google.cloud.dialogflow.cx.v3.ExportFlowRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L589}
  /// [google.cloud.dialogflow.cx.v3.ExportFlowResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/flow.proto#L617}
  ///
  future<StatusOr<google::cloud::dialogflow::cx::v3::ExportFlowResponse>>
  ExportFlow(
      google::cloud::dialogflow::cx::v3::ExportFlowRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<FlowsConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_FLOWS_CLIENT_H
