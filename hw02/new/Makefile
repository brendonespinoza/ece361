CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main
SOURCES = main.c reading.c stats.c histogram.c
HEADERS = reading.h stats.h histogram.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)