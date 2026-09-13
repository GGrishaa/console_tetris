GCC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
LDFLAGS = -lncurses

all: tetris run

tetris: main.o figure.o manipulate.o draw.o scenes.o
	$(GCC) $^ $(LDFLAGS) -o $@

main.o: main.c figure.h
	$(GCC) $< -c $(CFLAGS) -o $@

figure.o: figure.c figure.h manipulate.h
	$(GCC) $< -c $(CFLAGS) -o $@

manipulate.o: manipulate.c manipulate.h figure.h
	$(GCC) $< -c $(CFLAGS) -o $@

draw.o: draw.c draw.h figure.h scenes.h
	$(GCC) $< -c $(CFLAGS) -o $@

scenes.o: scenes.c scenes.h
	$(GCC) $< -c $(CFLAGS) -o $@

run: tetris
	./tetris

clean:
	rm -f tetris figure.o main.o draw.o manipulate.o scenes.o
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