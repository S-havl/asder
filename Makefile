CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -Iinclude -std=gnu11
TARGET = asder

SRC = src/main.c src/engine.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f src/*.o $(TARGET)

.PHONY: all clean run
