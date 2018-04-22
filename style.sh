#!/bin/sh

set -ue
set -v

# Check coding style
cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet `find ./ -name "*.cpp"`
cpplint `find ./ -name "*.cpp"`

# Check pdd tokens
pdd > /dev/null
