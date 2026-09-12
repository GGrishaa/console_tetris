#ifndef FIGURE_H
#define FIGURE_H
#define _XOPEN_SOURCE_EXTENDED 1

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

void draw_figure(struct figure* f);

void move_left_figure(struct figure* f);
void move_right_figure(struct figure* f);
void move_down_figure(struct figure* f);

void rotate_I_to0(struct figure* f);
void rotate_I_to1(struct figure* f);
void rotate_I(struct figure* f);
void rotate_J_to0(struct figure* f);
void rotate_J_to1(struct figure* f);
void rotate_J_to2(struct figure* f);
void rotate_J_to3(struct figure* f);
void rotate_J(struct figure* f);
void rotate_L_to0(struct figure* f);
void rotate_L_to1(struct figure* f);
void rotate_L_to2(struct figure* f);
void rotate_L_to3(struct figure* f);
void rotate_L(struct figure* f);
void rotate_S_to0(struct figure* f);
void rotate_S_to1(struct figure* f);
void rotate_S(struct figure* f);
void rotate_T_to0(struct figure* f);
void rotate_T_to1(struct figure* f);
void rotate_T_to2(struct figure* f);
void rotate_T_to3(struct figure* f);
void rotate_T(struct figure* f);
void rotate_Z_to0(struct figure* f);
void rotate_Z_to1(struct figure* f);
void rotate_Z(struct figure* f);

void rotate_figure(struct figure* f);

#endif