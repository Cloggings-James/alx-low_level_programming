#!/bin/bash
gcc -shared -o /tmp/winning.so -fPIC /path/to/your/c_code.c
export LD_PRELOAD=/tmp/winning.so

