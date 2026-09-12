#ifndef DRAW_H
#define DRAW_H

#define _XOPEN_SOURCE_EXTENDED 1
#include <locale.h>
#include <ncurses.h>

#include "figure.h"

void draw_figure(struct figure* f);

void draw_field(struct figure* f, struct figure* next, struct field* fld);

void spawn_figure(struct figure* cur, struct figure* next, enum TYPE* r,
                  enum TYPE* r2);

void initialization(struct figure* f, struct figure* next, struct field* fld,
                    enum TYPE* r, enum TYPE* r2);

void remove_line(struct field* fld, int n);

void check_lines(struct field* fld);

#endif