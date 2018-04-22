#!/bin/sh

set -ue
set -v

# Check coding style
cppcheck -I. --enable=all --quiet *.cpp test/*.cpp
cpplint *.cpp test/*.cpp

# Check pdd tokens
pdd > /dev/null
