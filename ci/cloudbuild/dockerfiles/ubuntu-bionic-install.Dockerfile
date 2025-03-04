# Copyright 2021 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

FROM ubuntu:bionic
ARG NCPU=4

RUN apt-get update && \
    apt-get --no-install-recommends install -y \
        automake \
        build-essential \
        ccache \
        clang \
        clang-9 \
        cmake \
        ctags \
        curl \
        gawk \
        git \
        gcc \
        g++ \
        cmake \
        libcurl4-openssl-dev \
        libssl-dev \
        libtool \
        llvm-9 \
        lsb-release \
        make \
        ninja-build \
        patch \
        pkg-config \
        python3 \
        python3-dev \
        python3-pip \
        tar \
        unzip \
        zip \
        wget \
        zlib1g-dev \
        apt-utils \
        ca-certificates \
        apt-transport-https

# Install all the direct (and indirect) dependencies for google-cloud-cpp.
# Use a different directory for each build, and remove the downloaded
# files and any temporary artifacts after a successful build to keep the
# image smaller (and with fewer layers)

WORKDIR /var/tmp/build/abseil-cpp
RUN curl -sSL https://github.com/abseil/abseil-cpp/archive/20220623.1.tar.gz | \
    tar -xzf - --strip-components=1 && \
    sed -i 's/^#define ABSL_OPTION_USE_\(.*\) 2/#define ABSL_OPTION_USE_\1 0/' "absl/base/options.h" && \
    cmake \
      -DCMAKE_BUILD_TYPE="Release" \
      -DABSL_BUILD_TESTING=OFF \
      -DBUILD_SHARED_LIBS=yes \
      -H. -Bcmake-out -GNinja && \
    cmake --build cmake-out --target install -- -j ${NCPU} && \
    ldconfig && \
    cd /var/tmp && rm -fr build

WORKDIR /var/tmp/build/googletest
RUN curl -sSL https://github.com/google/googletest/archive/release-1.12.1.tar.gz | \
    tar -xzf - --strip-components=1 && \
    cmake \
      -DCMAKE_BUILD_TYPE="Release" \
      -DBUILD_SHARED_LIBS=yes \
      -DCMAKE_CXX_STANDARD=11 \
      -H. -Bcmake-out/googletest && \
    cmake --build cmake-out/googletest --target install -- -j ${NCPU} && \
    ldconfig && \
    cd /var/tmp && rm -fr build

WORKDIR /var/tmp/build/benchmark
RUN curl -sSL https://github.com/google/benchmark/archive/v1.7.0.tar.gz | \
    tar -xzf - --strip-components=1 && \
    cmake \
        -DCMAKE_BUILD_TYPE="Release" \
        -DBUILD_SHARED_LIBS=yes \
        -DBENCHMARK_ENABLE_TESTING=OFF \
        -H. -Bcmake-out -GNinja && \
    cmake --build cmake-out --target install -- -j ${NCPU} && \
    ldconfig && \
    cd /var/tmp && rm -fr build

WORKDIR /var/tmp/build/crc32c
RUN curl -sSL https://github.com/google/crc32c/archive/1.1.2.tar.gz | \
    tar -xzf - --strip-components=1 && \
    cmake \
      -DCMAKE_BUILD_TYPE="Release" \
      -DBUILD_SHARED_LIBS=yes \
      -DCRC32C_BUILD_TESTS=OFF \
      -DCRC32C_BUILD_BENCHMARKS=OFF \
      -DCRC32C_USE_GLOG=OFF \
      -H. -Bcmake-out -GNinja && \
    cmake --build cmake-out --target install -- -j ${NCPU} && \
    ldconfig && \
    cd /var/tmp && rm -fr build

WORKDIR /var/tmp/build/nlohmann-json
RUN curl -sSL https://github.com/nlohmann/json/archive/v3.11.2.tar.gz | \
    tar -xzf - --strip-components=1 && \
    cmake \
      -DCMAKE_BUILD_TYPE="Release" \
      -DBUILD_SHARED_LIBS=yes \
      -DBUILD_TESTING=OFF \
      -DJSON_BuildTests=OFF \
      -H. -Bcmake-out -GNinja && \
    cmake --build cmake-out --target install -- -j ${NCPU} && \
    ldconfig && \
    cd /var/tmp && rm -fr build

WORKDIR /var/tmp/build/protobuf
RUN curl -sSL https://github.com/protocolbuffers/protobuf/archive/v21.10.tar.gz | \
    tar -xzf - --strip-components=1 && \
    cmake \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=yes \
        -Dprotobuf_BUILD_TESTS=OFF \
        -Dprotobuf_ABSL_PROVIDER=package \
        -H. -Bcmake-out -GNinja && \
    cmake --build cmake-out --target install -- -j ${NCPU} && \
    ldconfig && \
    cd /var/tmp && rm -fr build

WORKDIR /var/tmp/build/c-ares
RUN curl -sSL https://github.com/c-ares/c-ares/archive/refs/tags/cares-1_17_1.tar.gz | \
    tar -xzf - --strip-components=1 && \
    cmake \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=yes \
        -H. -Bcmake-out -GNinja && \
    cmake --build cmake-out --target install -- -j ${NCPU} && \
    ldconfig && \
    cd /var/tmp && rm -fr build

WORKDIR /var/tmp/build/re2
RUN curl -sSL https://github.com/google/re2/archive/2022-12-01.tar.gz | \
    tar -xzf - --strip-components=1 && \
    cmake -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=ON \
        -DRE2_BUILD_TESTING=OFF \
        -H. -Bcmake-out -GNinja && \
    cmake --build cmake-out --target install -- -j ${NCPU} && \
    ldconfig && \
    cd /var/tmp && rm -fr build

WORKDIR /var/tmp/build/grpc
RUN curl -sSL https://github.com/grpc/grpc/archive/v1.49.1.tar.gz | \
    tar -xzf - --strip-components=1 && \
    cmake \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=ON \
        -DgRPC_INSTALL=ON \
        -DgRPC_BUILD_TESTS=OFF \
        -DgRPC_ABSL_PROVIDER=package \
        -DgRPC_CARES_PROVIDER=package \
        -DgRPC_PROTOBUF_PROVIDER=package \
        -DgRPC_RE2_PROVIDER=package \
        -DgRPC_SSL_PROVIDER=package \
        -DgRPC_ZLIB_PROVIDER=package \
        -H. -Bcmake-out -GNinja && \
    cmake --build cmake-out --target install -- -j ${NCPU} && \
    ldconfig && \
    cd /var/tmp && rm -fr build

# Install Python packages used in the integration tests.
RUN update-alternatives --install /usr/bin/python python $(which python3) 10
RUN pip3 install setuptools wheel

# Install the Cloud SDK and some of the emulators. We use the emulators to run
# integration tests for the client libraries.
COPY . /var/tmp/ci
WORKDIR /var/tmp/downloads
RUN /var/tmp/ci/install-cloud-sdk.sh
ENV CLOUD_SDK_LOCATION=/usr/local/google-cloud-sdk
ENV PATH=${CLOUD_SDK_LOCATION}/bin:${PATH}
# The Cloud Pub/Sub emulator needs Java :shrug:
RUN apt update && (apt install -y openjdk-11-jre || apt install -y openjdk-9-jre)
