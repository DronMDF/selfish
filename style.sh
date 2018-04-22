#!/bin/sh

set -ue
set -v

# Check coding style
cppcheck -I. --enable=all --quiet *.cpp
cpplint *.cpp

# Check pdd tokens
pdd > /dev/null
