#ifndef FIGURE_H
#define FIGURE_H

#include <ncurses.h>
#include <stdlib.h>

enum TYPE {
  I = 1,
  J = 2,
  L = 3,
  O = 4,
  S = 5,
  T = 6,
  Z = 7,
};

int rand_type();

struct point {
  int x;
  int y;
};

struct figure {
  struct point p[4];
  enum TYPE type;
  int poses_count;
  int pos;
};

struct field {
  bool points[20][10];
};

void init_I(struct figure* f);
void init_J(struct figure* f);
void init_L(struct figure* f);
void init_O(struct figure* f);
void init_S(struct figure* f);
void init_T(struct figure* f);
void init_Z(struct figure* f);
void init_figure(struct figure* f, enum TYPE t, int y0, int x0);

int max_right(struct figure* f);
int max_left(struct figure* f);
int max_down(struct figure* f);

int can_be(struct figure* f, struct field* fld);
int can_right(struct figure* f, struct field* fld);
int can_left(struct figure* f, struct field* fld);
int can_down(struct figure* f, struct field* fld);
int can_rot(struct figure* f, struct field* fld);

void init_field(struct field* f);

#endif