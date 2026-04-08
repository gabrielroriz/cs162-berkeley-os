#!/bin/bash
set -e # Exit immediately if a command exits with a non-zero status.

C_FILE_NAME=$1
gcc "$C_FILE_NAME.c" -o "$C_FILE_NAME"
./"$C_FILE_NAME"
