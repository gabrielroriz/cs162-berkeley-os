CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = main
SRCS = main.c word.c
OBJS = $(SRCS:.c=.o)

# Default target: build the binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each .c file into a .o object file
%.o: %.c word.h
	$(CC) $(CFLAGS) -c $< -o $@

# Remove compiled files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
