LIBS="-lm"
FLAGS="-Wall -Wextra --std=c11 -ggdb"


set -xe
gcc $FLAGS main.c -o radix $LIBS
