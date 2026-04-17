#!/bin/sh

set -xe

gcc -Wall -Wextra -o bin/single single.c -lm
gcc -Wall -Wextra  -o bin/gates gates.c -lm