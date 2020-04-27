SRC = ./src/*.c
UTILS = ./src/utils/*c

INCDIR = ./inc

CL = clang

CLFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -o

BIN = race03

all:
	$(CL) $(CLFLAGS) $(BIN) -I $(INCDIR) $(SRC) $(UTILS)

uninstall:
	rm $(BIN)

clean:
	.PHONY

reinstall: uninstall all
