#!/bin/docker build --no-cache -t jakt:latest -f Dockerfile .
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y \
    && apt-get install -y \
        build-essential \
        cmake \
        git \
        ninja-build \
        clang-15 \
        libclang-15-dev \
        vim \
    && rm -rf /var/lib/apt/lists/

COPY . /project/jakt/
WORKDIR /project/jakt/

RUN ln -s /usr/bin/clang++-15 /usr/bin/clang++; \
    ln -s /usr/bin/clang-15 /usr/bin/clang; \
    ln -s /usr/bin/clang-cpp-15 /usr/bin/clang-cpp

# B-B-Blast the build dir, so we don't carry over any bad state from the host clone
RUN rm -rf build

RUN cmake -B build -GNinja -DFINAL_STAGE=1 -DJAKT_BUILD_TESTING= -DCMAKE_CXX_COMPILER=clang++-15 -DCMAKE_INSTALL_PREFIX=jakt-install
RUN ninja -C build install

RUN ln -s /project/jakt/jakt-install/bin/jakt /usr/bin/jakt

ENTRYPOINT ["/bin/bash"]

