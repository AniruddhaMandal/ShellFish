CC=gcc
SRC=src
BUILD=build
OBJ=$(BUILD)/obj
LIBS=-lreadline

all: build main

main: main.o
	gcc -o $(BUILD)/shellfish $(OBJ)/main.o $(LIBS) 

main.o: $(SRC)/main.c
	gcc -c $(SRC)/main.c -o $(OBJ)/main.o

build:
	mkdir -p build
	mkdir -p build/obj

clean:
	rm -rf build