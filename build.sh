#! /usr/bin/env bash

gcc main.c -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./game
rm -f game
