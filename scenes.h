#ifndef SCENES_H
#define SCENES_H
#define _XOPEN_SOURCE_EXTENDED 1
#include <ncurses.h>

int draw_welcome();
void draw_rules();
void draw_end(int* sc, int* rec);

#endif