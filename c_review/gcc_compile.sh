#!/bin/bash
set -e

C_FILE_NAME=$1
gcc "$C_FILE_NAME.c" -o "$C_FILE_NAME"
./"$C_FILE_NAME"
