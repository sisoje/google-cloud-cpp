// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/common_options.h"
#include "google/cloud/internal/external_account_parsing.h"
#include "google/cloud/internal/getenv.h"
#include "google/cloud/internal/oauth2_external_account_credentials.h"
#include "google/cloud/internal/rest_client.h"
#include "google/cloud/testing_util/status_matchers.h"
#include <gmock/gmock.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <thread>

namespace google {
namespace cloud {
namespace oauth2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace {

using ::google::cloud::internal::GetEnv;
using ::testing::IsEmpty;

TEST(ExternalAccountIntegrationTest, UrlSourced) {
  auto filename = GetEnv("GOOGLE_CLOUD_CPP_EXTERNAL_ACCOUNT_FILE");
  if (!filename.has_value()) GTEST_SKIP();
  auto is = std::ifstream(*filename);
  auto contents = std::string{std::istreambuf_iterator<char>{is.rdbuf()}, {}};
  ASSERT_FALSE(is.bad());
  ASSERT_FALSE(is.fail());

  auto ec = internal::ErrorContext(
      {{"GOOGLE_CLOUD_CPP_EXTERNAL_ACCOUNT_FILE", *filename},
       {"program", "test"}});
  auto info = ParseExternalAccountConfiguration(contents, ec);
  ASSERT_STATUS_OK(info);

  auto make_client = [](Options opts = {}) {
    return rest_internal::MakeDefaultRestClient("", std::move(opts));
  };
  auto credentials = ExternalAccountCredentials(*info, make_client);
  // Anything involving HTTP requests may fail and needs a retry loop.
  auto now = std::chrono::system_clock::now();
  auto access_token = [&]() -> StatusOr<internal::AccessToken> {
    Status last_status;
    auto delay = std::chrono::seconds(1);
    for (int i = 0; i != 5; ++i) {
      if (i != 0) std::this_thread::sleep_for(delay);
      now = std::chrono::system_clock::now();
      auto access_token = credentials.GetToken(now);
      if (access_token) return access_token;
      last_status = std::move(access_token).status();
      delay *= 2;
    }
    return last_status;
  }();
  ASSERT_STATUS_OK(access_token);
  EXPECT_GT(access_token->expiration, now);
  EXPECT_THAT(access_token->token.substr(0, 32), Not(IsEmpty()));
}

}  // namespace
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace oauth2_internal
}  // namespace cloud
}  // namespace google
