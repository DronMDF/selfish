#!/bin/sh

set -ue
set -v

# Check coding style
cppcheck -I. --enable=all --quiet `find ./ -name "*.cpp"`
cpplint `find ./ -name "*.cpp"`

# Check pdd tokens
pdd > /dev/null
