#!/bin/bash

FLAGS="-Wall -Wextra -Werror -std=c++14 -g"
FILES="wasm.cpp main.cpp"

if [[ $# -eq 0 ]]; then
  echo "Usage: $0 [all|clean]"
  exit 1
fi

if [[ $1 = all ]]; then
  g++ $FLAGS $FILES -o wasmrt
elif [[ $1 = clean ]]; then
  rm -f *.o wasmrt
fi

exit 0

