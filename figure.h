#ifndef FIGURE_H
#define FIGURE_H

#include <ncurses.h>

enum TYPE {
  I = 1,
  J = 2,
  L = 3,
  O = 4,
  S = 5,
  T = 6,
  Z = 7,
};

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

#endif