#!/bin/sh
#DESENVOLVIDO POR Leonardo Correa

gcc -p client.c company.c principal.c -o principal -lm
./principal
