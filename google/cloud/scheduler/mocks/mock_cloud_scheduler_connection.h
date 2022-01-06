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
// source: google/cloud/scheduler/v1/cloudscheduler.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SCHEDULER_MOCKS_MOCK_CLOUD_SCHEDULER_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SCHEDULER_MOCKS_MOCK_CLOUD_SCHEDULER_CONNECTION_H

#include "google/cloud/scheduler/cloud_scheduler_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace scheduler_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MockCloudSchedulerConnection
    : public scheduler::CloudSchedulerConnection {
 public:
  MOCK_METHOD(StreamRange<google::cloud::scheduler::v1::Job>, ListJobs,
              (google::cloud::scheduler::v1::ListJobsRequest request),
              (override));

  MOCK_METHOD(StatusOr<google::cloud::scheduler::v1::Job>, GetJob,
              (google::cloud::scheduler::v1::GetJobRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::cloud::scheduler::v1::Job>, CreateJob,
              (google::cloud::scheduler::v1::CreateJobRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::cloud::scheduler::v1::Job>, UpdateJob,
              (google::cloud::scheduler::v1::UpdateJobRequest const& request),
              (override));

  MOCK_METHOD(Status, DeleteJob,
              (google::cloud::scheduler::v1::DeleteJobRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::cloud::scheduler::v1::Job>, PauseJob,
              (google::cloud::scheduler::v1::PauseJobRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::cloud::scheduler::v1::Job>, ResumeJob,
              (google::cloud::scheduler::v1::ResumeJobRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::cloud::scheduler::v1::Job>, RunJob,
              (google::cloud::scheduler::v1::RunJobRequest const& request),
              (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace scheduler_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SCHEDULER_MOCKS_MOCK_CLOUD_SCHEDULER_CONNECTION_H
