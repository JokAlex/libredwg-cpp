FROM ubuntu:24.04

RUN set -ex; \
    export DEBIAN_FRONTEND=noninteractive; \
    apt-get update; 

RUN apt-get --yes -qq install --no-install-recommends \
    build-essential gcc cmake python3 pip python3-dev python3-pytest

WORKDIR /libredwg-cpp
COPY . .

RUN mkdir ./build && cd ./build && cmake .. && cmake --build . && cmake --install .
