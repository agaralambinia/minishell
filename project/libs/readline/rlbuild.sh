#! /bin/sh
mkdir rl_lib
cd readline
./configure --prefix=$(pwd)/../rl_lib
make
make install
