#!/bin/sh
DIRS="include src"
clang-format --verbose -i `find $DIRS -name "*.c" -or -name "*.h"`
