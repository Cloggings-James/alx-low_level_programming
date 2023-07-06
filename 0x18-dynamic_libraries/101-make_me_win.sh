#!/bin/bash
wget -q -O /tmp/gm https://url/to/gm_program
chmod 755 /tmp/gm
export LD_PRELOAD=/path/to/101-make_me_win.so
/tmp/gm 9 8 10 24 75 9

