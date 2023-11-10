#!/bin/bash

gcc -o ./make/output.exe  ./brain/main.c ./ec_dc_interface/*.c ./interface/*.c ./data/*.c
./make/output.exe