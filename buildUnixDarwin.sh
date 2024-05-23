#! /bin/sh
#! working fine on MacOS- !Todo test for Linux
mkdir build
cd build
cmake ..
cd ..
cmake --build build
build/project