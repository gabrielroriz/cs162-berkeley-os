#!/bin/bash
set -e # Exit immediately if a command exits with a non-zero status.

C_FOLDER_NAME=$1
cd "./$C_FOLDER_NAME"

C_FILE_NAME=$2
C_ARGUMENTS="${@:3}" # Get all arguments starting from the third one

# Check if a Makefile exists, if it does, use it to compile the code, 
# otherwise compile the C file directly
if [ -f "Makefile" ]; then
    make -s
else
    gcc "$C_FILE_NAME.c" -o "$C_FILE_NAME"
fi

./"$C_FILE_NAME" "$C_ARGUMENTS"
