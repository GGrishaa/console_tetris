#ifndef DRAW_H
#define DRAW_H

#define _XOPEN_SOURCE_EXTENDED 1
#define RECORD_FILE "record.txt"

#include <locale.h>
#include <ncurses.h>
#include <stdio.h>

#include "figure.h"
#include "scenes.h"

void draw_figure(struct figure* f);

void draw_field(struct figure* f, struct figure* next, struct field* fld,
                int* score, int* record);

int spawn_figure(struct figure* cur, struct figure* next, struct field* fld,
                 enum TYPE* r, enum TYPE* r2);

int initialization(struct figure* f, struct figure* next, struct field* fld,
                   enum TYPE* r, enum TYPE* r2, int* score, int* record);

void denitialization(int* score, int* record);

void remove_line(struct field* fld, int n);

void check_lines(struct field* fld, int* score, int* cycles, int* final_cycles);

#endif