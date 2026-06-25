CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = asder
SRC = src/asder.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -rf $(TARGET)

.PHONY: all clean run