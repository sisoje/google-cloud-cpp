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
// source: google/cloud/networkconnectivity/v1/hub.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NETWORKCONNECTIVITY_MOCKS_MOCK_HUB_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NETWORKCONNECTIVITY_MOCKS_MOCK_HUB_CONNECTION_H

#include "google/cloud/networkconnectivity/hub_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace networkconnectivity_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * A class to mock `HubServiceConnection`.
 *
 * Application developers may want to test their code with simulated responses,
 * including errors, from an object of type `HubServiceClient`. To do so,
 * construct an object of type `HubServiceClient` with an instance of this
 * class. Then use the Google Test framework functions to program the behavior
 * of this mock.
 *
 * @see [This example][bq-mock] for how to test your application with
 * GoogleTest. While the example showcases types from the BigQuery library, the
 * underlying principles apply for any pair of `*Client` and `*Connection`.
 *
 * [bq-mock]: @googleapis_dev_link{bigquery,bigquery-read-mock.html}
 */
class MockHubServiceConnection
    : public networkconnectivity::HubServiceConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(StreamRange<google::cloud::networkconnectivity::v1::Hub>,
              ListHubs,
              (google::cloud::networkconnectivity::v1::ListHubsRequest request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::networkconnectivity::v1::Hub>, GetHub,
      (google::cloud::networkconnectivity::v1::GetHubRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::networkconnectivity::v1::Hub>>, CreateHub,
      (google::cloud::networkconnectivity::v1::CreateHubRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::networkconnectivity::v1::Hub>>, UpdateHub,
      (google::cloud::networkconnectivity::v1::UpdateHubRequest const& request),
      (override));

  MOCK_METHOD(
      future<
          StatusOr<google::cloud::networkconnectivity::v1::OperationMetadata>>,
      DeleteHub,
      (google::cloud::networkconnectivity::v1::DeleteHubRequest const& request),
      (override));

  MOCK_METHOD(
      StreamRange<google::cloud::networkconnectivity::v1::Spoke>, ListSpokes,
      (google::cloud::networkconnectivity::v1::ListSpokesRequest request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::networkconnectivity::v1::Spoke>, GetSpoke,
      (google::cloud::networkconnectivity::v1::GetSpokeRequest const& request),
      (override));

  MOCK_METHOD(future<StatusOr<google::cloud::networkconnectivity::v1::Spoke>>,
              CreateSpoke,
              (google::cloud::networkconnectivity::v1::CreateSpokeRequest const&
                   request),
              (override));

  MOCK_METHOD(future<StatusOr<google::cloud::networkconnectivity::v1::Spoke>>,
              UpdateSpoke,
              (google::cloud::networkconnectivity::v1::UpdateSpokeRequest const&
                   request),
              (override));

  MOCK_METHOD(
      future<
          StatusOr<google::cloud::networkconnectivity::v1::OperationMetadata>>,
      DeleteSpoke,
      (google::cloud::networkconnectivity::v1::DeleteSpokeRequest const&
           request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace networkconnectivity_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NETWORKCONNECTIVITY_MOCKS_MOCK_HUB_CONNECTION_H
