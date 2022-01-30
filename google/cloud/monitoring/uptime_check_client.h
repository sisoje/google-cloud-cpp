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
// source: google/monitoring/v3/uptime_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_UPTIME_CHECK_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_UPTIME_CHECK_CLIENT_H

#include "google/cloud/monitoring/uptime_check_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// The UptimeCheckService API is used to manage (list, create, delete, edit)
/// Uptime check configurations in the Stackdriver Monitoring product. An Uptime
/// check is a piece of configuration that determines which resources and
/// services to monitor for availability. These configurations can also be
/// configured interactively by navigating to the [Cloud Console]
/// (http://console.cloud.google.com), selecting the appropriate project,
/// clicking on "Monitoring" on the left-hand side to navigate to Stackdriver,
/// and then clicking on "Uptime".
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
class UptimeCheckServiceClient {
 public:
  explicit UptimeCheckServiceClient(
      std::shared_ptr<UptimeCheckServiceConnection> connection,
      Options options = {});
  ~UptimeCheckServiceClient();

  //@{
  // @name Copy and move support
  UptimeCheckServiceClient(UptimeCheckServiceClient const&) = default;
  UptimeCheckServiceClient& operator=(UptimeCheckServiceClient const&) =
      default;
  UptimeCheckServiceClient(UptimeCheckServiceClient&&) = default;
  UptimeCheckServiceClient& operator=(UptimeCheckServiceClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(UptimeCheckServiceClient const& a,
                         UptimeCheckServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(UptimeCheckServiceClient const& a,
                         UptimeCheckServiceClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Lists the existing valid Uptime check configurations for the project
  /// (leaving out any invalid configurations).
  ///
  /// @param parent  Required. The
  /// [project](https://cloud.google.com/monitoring/api/v3#project_name)
  ///  whose Uptime check configurations are listed. The format is:
  ///      projects/[PROJECT_ID_OR_NUMBER]
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::UptimeCheckConfig,google/monitoring/v3/uptime.proto#L110}
  ///
  /// [google.monitoring.v3.ListUptimeCheckConfigsRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L109}
  /// [google.monitoring.v3.UptimeCheckConfig]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime.proto#L110}
  ///
  StreamRange<google::monitoring::v3::UptimeCheckConfig> ListUptimeCheckConfigs(
      std::string const& parent, Options options = {});

  ///
  /// Lists the existing valid Uptime check configurations for the project
  /// (leaving out any invalid configurations).
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::ListUptimeCheckConfigsRequest,google/monitoring/v3/uptime_service.proto#L109}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::UptimeCheckConfig,google/monitoring/v3/uptime.proto#L110}
  ///
  /// [google.monitoring.v3.ListUptimeCheckConfigsRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L109}
  /// [google.monitoring.v3.UptimeCheckConfig]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime.proto#L110}
  ///
  StreamRange<google::monitoring::v3::UptimeCheckConfig> ListUptimeCheckConfigs(
      google::monitoring::v3::ListUptimeCheckConfigsRequest request,
      Options options = {});

  ///
  /// Gets a single Uptime check configuration.
  ///
  /// @param name  Required. The Uptime check configuration to retrieve. The
  /// format is:
  ///      projects/[PROJECT_ID_OR_NUMBER]/uptimeCheckConfigs/[UPTIME_CHECK_ID]
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::UptimeCheckConfig,google/monitoring/v3/uptime.proto#L110}
  ///
  /// [google.monitoring.v3.GetUptimeCheckConfigRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L151}
  /// [google.monitoring.v3.UptimeCheckConfig]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime.proto#L110}
  ///
  StatusOr<google::monitoring::v3::UptimeCheckConfig> GetUptimeCheckConfig(
      std::string const& name, Options options = {});

  ///
  /// Gets a single Uptime check configuration.
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::GetUptimeCheckConfigRequest,google/monitoring/v3/uptime_service.proto#L151}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::UptimeCheckConfig,google/monitoring/v3/uptime.proto#L110}
  ///
  /// [google.monitoring.v3.GetUptimeCheckConfigRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L151}
  /// [google.monitoring.v3.UptimeCheckConfig]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime.proto#L110}
  ///
  StatusOr<google::monitoring::v3::UptimeCheckConfig> GetUptimeCheckConfig(
      google::monitoring::v3::GetUptimeCheckConfigRequest const& request,
      Options options = {});

  ///
  /// Creates a new Uptime check configuration.
  ///
  /// @param parent  Required. The
  /// [project](https://cloud.google.com/monitoring/api/v3#project_name) in
  ///  which to create the Uptime check. The format is:
  ///      projects/[PROJECT_ID_OR_NUMBER]
  /// @param uptime_check_config  Required. The new Uptime check configuration.
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::UptimeCheckConfig,google/monitoring/v3/uptime.proto#L110}
  ///
  /// [google.monitoring.v3.CreateUptimeCheckConfigRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L164}
  /// [google.monitoring.v3.UptimeCheckConfig]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime.proto#L110}
  ///
  StatusOr<google::monitoring::v3::UptimeCheckConfig> CreateUptimeCheckConfig(
      std::string const& parent,
      google::monitoring::v3::UptimeCheckConfig const& uptime_check_config,
      Options options = {});

  ///
  /// Creates a new Uptime check configuration.
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::CreateUptimeCheckConfigRequest,google/monitoring/v3/uptime_service.proto#L164}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::UptimeCheckConfig,google/monitoring/v3/uptime.proto#L110}
  ///
  /// [google.monitoring.v3.CreateUptimeCheckConfigRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L164}
  /// [google.monitoring.v3.UptimeCheckConfig]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime.proto#L110}
  ///
  StatusOr<google::monitoring::v3::UptimeCheckConfig> CreateUptimeCheckConfig(
      google::monitoring::v3::CreateUptimeCheckConfigRequest const& request,
      Options options = {});

  ///
  /// Updates an Uptime check configuration. You can either replace the entire
  /// configuration with a new one or replace only certain fields in the current
  /// configuration by specifying the fields to be updated via `updateMask`.
  /// Returns the updated configuration.
  ///
  /// @param uptime_check_config  Required. If an `updateMask` has been
  /// specified, this field gives
  ///  the values for the set of fields mentioned in the `updateMask`. If an
  ///  `updateMask` has not been given, this Uptime check configuration replaces
  ///  the current configuration. If a field is mentioned in `updateMask` but
  ///  the corresonding field is omitted in this partial Uptime check
  ///  configuration, it has the effect of deleting/clearing the field from the
  ///  configuration on the server.
  ///  The following fields can be updated: `display_name`,
  ///  `http_check`, `tcp_check`, `timeout`, `content_matchers`, and
  ///  `selected_regions`.
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::UptimeCheckConfig,google/monitoring/v3/uptime.proto#L110}
  ///
  /// [google.monitoring.v3.UpdateUptimeCheckConfigRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L181}
  /// [google.monitoring.v3.UptimeCheckConfig]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime.proto#L110}
  ///
  StatusOr<google::monitoring::v3::UptimeCheckConfig> UpdateUptimeCheckConfig(
      google::monitoring::v3::UptimeCheckConfig const& uptime_check_config,
      Options options = {});

  ///
  /// Updates an Uptime check configuration. You can either replace the entire
  /// configuration with a new one or replace only certain fields in the current
  /// configuration by specifying the fields to be updated via `updateMask`.
  /// Returns the updated configuration.
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::UpdateUptimeCheckConfigRequest,google/monitoring/v3/uptime_service.proto#L181}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::UptimeCheckConfig,google/monitoring/v3/uptime.proto#L110}
  ///
  /// [google.monitoring.v3.UpdateUptimeCheckConfigRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L181}
  /// [google.monitoring.v3.UptimeCheckConfig]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime.proto#L110}
  ///
  StatusOr<google::monitoring::v3::UptimeCheckConfig> UpdateUptimeCheckConfig(
      google::monitoring::v3::UpdateUptimeCheckConfigRequest const& request,
      Options options = {});

  ///
  /// Deletes an Uptime check configuration. Note that this method will fail
  /// if the Uptime check configuration is referenced by an alert policy or
  /// other dependent configs that would be rendered invalid by the deletion.
  ///
  /// @param name  Required. The Uptime check configuration to delete. The
  /// format is:
  ///      projects/[PROJECT_ID_OR_NUMBER]/uptimeCheckConfigs/[UPTIME_CHECK_ID]
  /// @param options  Optional. Operation options.
  ///
  /// [google.monitoring.v3.DeleteUptimeCheckConfigRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L203}
  ///
  Status DeleteUptimeCheckConfig(std::string const& name, Options options = {});

  ///
  /// Deletes an Uptime check configuration. Note that this method will fail
  /// if the Uptime check configuration is referenced by an alert policy or
  /// other dependent configs that would be rendered invalid by the deletion.
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::DeleteUptimeCheckConfigRequest,google/monitoring/v3/uptime_service.proto#L203}
  /// @param options  Optional. Operation options.
  ///
  /// [google.monitoring.v3.DeleteUptimeCheckConfigRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L203}
  ///
  Status DeleteUptimeCheckConfig(
      google::monitoring::v3::DeleteUptimeCheckConfigRequest const& request,
      Options options = {});

  ///
  /// Returns the list of IP addresses that checkers run from
  ///
  /// @param request
  /// @googleapis_link{google::monitoring::v3::ListUptimeCheckIpsRequest,google/monitoring/v3/uptime_service.proto#L216}
  /// @param options  Optional. Operation options.
  /// @return
  /// @googleapis_link{google::monitoring::v3::UptimeCheckIp,google/monitoring/v3/uptime.proto#L371}
  ///
  /// [google.monitoring.v3.ListUptimeCheckIpsRequest]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime_service.proto#L216}
  /// [google.monitoring.v3.UptimeCheckIp]:
  /// @googleapis_reference_link{google/monitoring/v3/uptime.proto#L371}
  ///
  StreamRange<google::monitoring::v3::UptimeCheckIp> ListUptimeCheckIps(
      google::monitoring::v3::ListUptimeCheckIpsRequest request,
      Options options = {});

 private:
  std::shared_ptr<UptimeCheckServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_UPTIME_CHECK_CLIENT_H
