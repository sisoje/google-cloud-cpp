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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_EXTERNAL_ACCOUNT_TOKEN_SOURCE_URL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_EXTERNAL_ACCOUNT_TOKEN_SOURCE_URL_H

#include "google/cloud/internal/error_metadata.h"
#include "google/cloud/internal/oauth2_external_account_token_source.h"
#include "google/cloud/version.h"
#include <nlohmann/json.hpp>
#include <functional>

namespace google {
namespace cloud {
namespace oauth2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * Creates an `ExternalAccountTokenSource` for URL-based credential sources.
 *
 * External accounts credentials use [OAuth 2.0 Token Exchange][RFC 8693] to
 * convert a "subject token" into an "access token". The latter is used (as one
 * would expect) to access GCP services.
 *
 * External accounts may obtain the subject tokens from several different
 * sources. Tokens may be [url-sourced], meaning the client library needs to
 * fetch the subject token from a HTTP service. This function validates the
 * configuration for url-sourced subject tokens, and returns (if the validation
 * is successful) a functor to fetch the token from the URL.
 *
 * Note that fetching the token may fail after this function returns
 * successfully. For example, the server may be unreachable, or the returned
 * payload may fail to parse.
 *
 * [RFC 8693]: https://www.rfc-editor.org/rfc/rfc8693.html
 * [url-sourced]:
 * https://google.aip.dev/auth/4117#determining-the-subject-token-in-microsoft-azure-and-url-sourced-credentials
 */
StatusOr<ExternalAccountTokenSource> MakeExternalAccountTokenSourceUrl(
    nlohmann::json const& credentials_source, internal::ErrorContext const& ec);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace oauth2_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_INTERNAL_EXTERNAL_ACCOUNT_TOKEN_SOURCE_URL_H
