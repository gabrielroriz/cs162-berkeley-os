CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = main
SRCS = main.c word.c

$(TARGET): $(SRCS) word.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: clean
