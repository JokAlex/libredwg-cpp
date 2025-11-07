FROM ubuntu:24.04

RUN set -ex; \
    export DEBIAN_FRONTEND=noninteractive; \
    apt-get update; \
    apt-get --yes -qq install --no-install-recommends \
    build-essential gcc cmake python3 pip python3-dev python3-virtualenv

WORKDIR /libredwg-cpp
COPY . .

RUN set -ex; \
    virtualenv -p python3 --activators bash ./env; \
    ./env/bin/pip install --upgrade pip; \
    ./env/bin/pip install --no-cache-dir .[tests]

# Tests running:
RUN . env/bin/activate; \
    cd tests \
    mkdir -p out_data \
    python -m pytest
