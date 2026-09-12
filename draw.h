#ifndef DRAW_H
#define DRAW_H

#define _XOPEN_SOURCE_EXTENDED 1
#include <ncurses.h>

#include "figure.h"

void draw_figure(struct figure* f);

void draw_field(struct figure* f, struct figure* next);

#endif