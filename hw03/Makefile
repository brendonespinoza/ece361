CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main
SOURCES = ptr.c tests/test_ptr.c
HEADERS = ptr.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)