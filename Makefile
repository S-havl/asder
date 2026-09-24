CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -Iinclude -std=gnu11
TARGET = asder

SRC = src/main.c src/engine.c
OBJ = $(SRC:.c=.o)

FORMAT_FILES := $(shell find . -type d -name '$(BUILD)' -prune -false -o -type f \( -name '*.c' -o -name '*.h' \))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

format:
	@echo "Formatting the Asder source code..."
	@clang-format -i $(FORMAT_FILES)

clean:
	rm -f src/*.o $(TARGET)

.PHONY: all format clean run
