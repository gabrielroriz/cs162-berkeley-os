#!/bin/bash
set -e # Exit immediately if a command exits with a non-zero status.

C_FILE_NAME="${1%.c}"
gcc "$C_FILE_NAME.c" -o "$C_FILE_NAME"
DIR=$(dirname "$C_FILE_NAME")
BIN=$(basename "$C_FILE_NAME")
(cd "$DIR" && ./"$BIN")
