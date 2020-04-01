#!/bin/bash

set -e

mkdir -p bin
mkdir -p obj
g++ -Wall -Wextra -Werror \
  -std=c++14 -g \
  src/wasm.cpp src/main.cpp \
  -o bin/wasmrt

exit 0

