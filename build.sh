#!/bin/sh

set -xe
mkdir -p build

clang++ $(pkg-config --libs --cflags sdl2) -o build/main main.cpp
