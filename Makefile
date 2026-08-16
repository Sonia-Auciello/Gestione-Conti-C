CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
TARGET = gestione_conti
SRC = src/main.c src/conto.c src/funzioni.c src/gestione_file.c src/testing.c

ifeq ($(OS),Windows_NT)
	TARGET := $(TARGET).exe
endif

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f gestione_conti gestione_conti.exe dati_conti.bin

.PHONY: all run clean
