GCC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
LDFLAGS = -lncurses

all: tetris run

tetris: main.o figure.o
	$(GCC) $^ $(LDFLAGS) -o $@

main.o: main.c figure.h
	$(GCC) $< -c $(CFLAGS) -o $@

figure.o: figure.c figure.h
	$(GCC) $< -c $(CFLAGS) -o $@

run: tetris
	./tetris

clean:
	rm -f tetris figure.o main.o
	clear

rebuild: clean all

clang:
	touch .clang-format
	echo "---" > .clang-format
	echo "BasedOnStyle: Google" >> .clang-format
	clang-format -i *.c *.h
	rm -f .clang-format
	clear


.PHONY = all tetris run clean rebuild clang