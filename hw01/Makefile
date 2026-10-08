CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = test_bits
SOURCES = test_bits.c bits.c status.c
HEADERS = bits.h status.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)