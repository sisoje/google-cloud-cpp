// Copyright 2021 Google LLC
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

#ifndef GOOGLE_CLOUD_CPP_GENERATOR_INTERNAL_SCAFFOLD_GENERATOR_H
#define GOOGLE_CLOUD_CPP_GENERATOR_INTERNAL_SCAFFOLD_GENERATOR_H

#include "absl/types/optional.h"
#include "generator/generator_config.pb.h"
#include <iosfwd>
#include <map>
#include <string>

namespace google {
namespace cloud {
namespace generator_internal {

/**
 * Returns the library short name from its path.
 *
 * In `google-cloud-cpp` libraries called `foo` live in the `google/cloud/foo`
 * directory. The names of CMake targets, Bazel rules, pkg-config modules,
 * features, etc. are based on the library name. This function returns the
 * library name given a service configuration's product path.
 */
std::string LibraryName(std::string const& product_path);

/**
 * Returns the path to the library directory.
 *
 * Extract the library path (e.g. `google/cloud/foo/`) from a product path (e.g.
 * `google/cloud/foo/bar/v1`).
 */
std::string LibraryPath(std::string const& product_path);

/**
 * Returns the relative path to the service from its library path.
 *
 * Extract the relative path (e.g. `bar/v1/`) from a product path (e.g.
 * `google/cloud/foo/bar/v1`).
 */
std::string ServiceSubdirectory(std::string const& product_path);

/**
 * Returns the name of the doxygen refgroup for options in a given product path.
 *
 * There is a single refgroup for all options in a library. For example, the
 * options in `google/cloud/foo/v1/` and `google/cloud/foo/bar/v1` will both map
 * to the group: `google-cloud-foo-options`.
 */
std::string OptionsGroup(std::string const& product_path);

std::map<std::string, std::string> ScaffoldVars(
    std::string const& googleapis_path,
    google::cloud::cpp::generator::ServiceConfiguration const& service,
    bool experimental);

void MakeDirectory(std::string const& path);

void GenerateScaffold(
    std::string const& googleapis_path, std::string const& output_path,
    google::cloud::cpp::generator::ServiceConfiguration const& service,
    bool experimental);

void GenerateCmakeConfigIn(std::ostream& os,
                           std::map<std::string, std::string> const& variables);
void GenerateReadme(std::ostream& os,
                    std::map<std::string, std::string> const& variables);
void GenerateBuild(std::ostream& os,
                   std::map<std::string, std::string> const& variables);
void GenerateCMakeLists(std::ostream& os,
                        std::map<std::string, std::string> const& variables);
void GenerateDoxygenMainPage(
    std::ostream& os, std::map<std::string, std::string> const& variables);
void GenerateDoxygenOptionsPage(
    std::ostream& os, std::map<std::string, std::string> const& variables);
void GenerateQuickstartReadme(
    std::ostream& os, std::map<std::string, std::string> const& variables);
void GenerateQuickstartSkeleton(
    std::ostream& os, std::map<std::string, std::string> const& variables);
void GenerateQuickstartCMake(
    std::ostream& os, std::map<std::string, std::string> const& variables);
void GenerateQuickstartMakefile(
    std::ostream& os, std::map<std::string, std::string> const& variables);
void GenerateQuickstartWorkspace(
    std::ostream& os, std::map<std::string, std::string> const& variables);
void GenerateQuickstartBuild(
    std::ostream& os, std::map<std::string, std::string> const& variables);
void GenerateQuickstartBazelrc(
    std::ostream& os, std::map<std::string, std::string> const& variables);
void GenerateSamplesBuild(std::ostream& os,
                          std::map<std::string, std::string> const& variables);
void GenerateSamplesCMake(std::ostream& os,
                          std::map<std::string, std::string> const& variables);

}  // namespace generator_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GENERATOR_INTERNAL_SCAFFOLD_GENERATOR_H
