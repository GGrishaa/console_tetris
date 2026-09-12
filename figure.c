#include "figure.h"

#include "manipulate.h"

int rand_type() { return rand() % 7 + 1; }

void init_I(struct figure* f) {
  f->poses_count = 2;
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 - 1;
  f->p[1].x = x0;
  f->p[2].y = y0 + 1;
  f->p[2].x = x0;
  f->p[3].y = y0 + 2;
  f->p[3].x = x0;
}

void init_J(struct figure* f) {
  f->poses_count = 4;
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0;
  f->p[1].x = x0 - 1;
  f->p[2].y = y0 - 1;
  f->p[2].x = x0;
  f->p[3].y = y0 - 2;
  f->p[3].x = x0;
}

void init_L(struct figure* f) {
  f->poses_count = 4;
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 - 1;
  f->p[1].x = x0;
  f->p[2].y = y0 - 2;
  f->p[2].x = x0;
  f->p[3].y = y0;
  f->p[3].x = x0 + 1;
}

void init_O(struct figure* f) {
  f->poses_count = 1;
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 - 1;
  f->p[1].x = x0;
  f->p[2].y = y0 - 1;
  f->p[2].x = x0 - 1;
  f->p[3].y = y0;
  f->p[3].x = x0 - 1;
}

void init_S(struct figure* f) {
  f->poses_count = 2;
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0;
  f->p[1].x = x0 - 1;
  f->p[2].y = y0 - 1;
  f->p[2].x = x0;
  f->p[3].y = y0 - 1;
  f->p[3].x = x0 + 1;
}

void init_T(struct figure* f) {
  f->poses_count = 4;
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0;
  f->p[1].x = x0 - 1;
  f->p[2].y = y0;
  f->p[2].x = x0 + 1;
  f->p[3].y = y0 + 1;
  f->p[3].x = x0;
}

void init_Z(struct figure* f) {
  f->poses_count = 2;
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 - 1;
  f->p[1].x = x0 - 1;
  f->p[2].y = y0 - 1;
  f->p[2].x = x0;
  f->p[3].y = y0;
  f->p[3].x = x0 + 1;
}

void init_figure(struct figure* f, enum TYPE t, int y0, int x0) {
  f->p[0].y = y0;
  f->p[0].x = x0;
  f->pos = 0;
  f->type = t;
  switch (t) {
    case I:
      init_I(f);
      break;
    case J:
      init_J(f);
      break;
    case L:
      init_L(f);
      break;
    case O:
      init_O(f);
      break;
    case S:
      init_S(f);
      break;
    case T:
      init_T(f);
      break;
    case Z:
      init_Z(f);
      break;
  }
}

int max_right(struct figure* f) {
  int max = 0;
  for (int i = 0; i < 4; ++i)
    if (f->p[i].x > max) max = f->p[i].x;
  return max;
}

int max_left(struct figure* f) {
  int min = 10;
  for (int i = 0; i < 4; ++i)
    if (f->p[i].x < min) min = f->p[i].x;
  return min;
}

int max_down(struct figure* f) {
  int max = 0;
  for (int i = 0; i < 4; ++i)
    if (f->p[i].y > max) max = f->p[i].y;
  return max;
}

int can_be(struct figure* f, struct field* fld) {
  bool ans = true;
  for (int k = 0; k < 4; ++k) {
    if (fld->points[f->p[k].y][f->p[k].x - 1]) ans = false;
  }
  return ans && max_right(f) <= 10 && max_left(f) >= 1 && max_down(f) <= 19;
}

int can_right(struct figure* f, struct field* fld) {
  move_right_figure(f);
  bool ans = can_be(f, fld);
  move_left_figure(f);
  return ans;
}

int can_left(struct figure* f, struct field* fld) {
  move_left_figure(f);
  bool ans = can_be(f, fld);
  move_right_figure(f);
  return ans;
}

int can_down(struct figure* f, struct field* fld) {
  move_down_figure(f);
  bool ans = can_be(f, fld);
  move_up_figure(f);
  return ans;
}

int can_rot(struct figure* f, struct field* fld) {
  (void)fld;
  if (f->type == O) return true;
  bool res;
  rotate_figure(f);
  res = can_be(f, fld);
  rotate_figure(f);
  rotate_figure(f);
  rotate_figure(f);
  return res;
}

void init_field(struct field* f) {
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 10; ++j) {
      f->points[i][j] = false;
    }
  }
}