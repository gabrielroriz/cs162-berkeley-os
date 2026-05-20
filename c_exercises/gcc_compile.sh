#!/bin/bash
set -e # Exit immediately if a command exits with a non-zero status.

DEBUG=0
ARGS=()
for arg in "$@"; do
    if [ "$arg" = "--debug" ]; then
        DEBUG=1
    else
        ARGS+=("$arg")
    fi
done

C_FOLDER_NAME=${ARGS[0]}
cd "./$C_FOLDER_NAME"

C_FILE_NAME=${ARGS[1]}
C_ARGUMENTS="${ARGS[@]:2}" # Get all arguments starting from the third one

# Check if a Makefile exists, if it does, use it to compile the code,
# otherwise compile the C file directly
if [ -f "Makefile" ]; then
    if [ "$DEBUG" -eq 1 ]; then
        make -s CFLAGS="-g"
    else
        make -s
    fi
else
    if [ "$DEBUG" -eq 1 ]; then
        gcc -g "$C_FILE_NAME.c" -o "$C_FILE_NAME"
    else
        gcc "$C_FILE_NAME.c" -o "$C_FILE_NAME"
    fi
fi

if [ "$DEBUG" -eq 1 ]; then
    gdb "./$C_FILE_NAME"
else
    ./"$C_FILE_NAME" "$C_ARGUMENTS"
fi
