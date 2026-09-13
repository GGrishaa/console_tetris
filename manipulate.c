#include "manipulate.h"

void move_left_figure(struct figure* f) {
  for (int i = 0; i < 4; ++i) f->p[i].x--;
}

void move_right_figure(struct figure* f) {
  for (int i = 0; i < 4; ++i) f->p[i].x++;
}

void move_down_figure(struct figure* f) {
  for (int i = 0; i < 4; ++i) f->p[i].y++;
}

void move_up_figure(struct figure* f) {
  for (int i = 0; i < 4; ++i) f->p[i].y--;
}

void extra_move_down(struct figure* f, struct field* fld) {
  do {
    move_down_figure(f);
  } while (can_be(f, fld));
  move_up_figure(f);
}

void rotate_I_to0(struct figure* f) { init_I(f); }
void rotate_I_to1(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0;
  f->p[1].x = x0 - 1;
  f->p[2].y = y0;
  f->p[2].x = x0 - 2;
  f->p[3].y = y0;
  f->p[3].x = x0 + 1;
}

void rotate_J_to0(struct figure* f) { init_J(f); }
void rotate_J_to1(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 - 1;
  f->p[1].x = x0;
  f->p[2].y = y0;
  f->p[2].x = x0 + 1;
  f->p[3].y = y0;
  f->p[3].x = x0 + 2;
}
void rotate_J_to2(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0;
  f->p[1].x = x0 + 1;
  f->p[2].y = y0 + 1;
  f->p[2].x = x0;
  f->p[3].y = y0 + 2;
  f->p[3].x = x0;
}
void rotate_J_to3(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 + 1;
  f->p[1].x = x0;
  f->p[2].y = y0;
  f->p[2].x = x0 - 1;
  f->p[3].y = y0;
  f->p[3].x = x0 - 2;
}

void rotate_L_to0(struct figure* f) { init_L(f); }
void rotate_L_to1(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 + 1;
  f->p[1].x = x0;
  f->p[2].y = y0;
  f->p[2].x = x0 + 1;
  f->p[3].y = y0;
  f->p[3].x = x0 + 2;
}
void rotate_L_to2(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0;
  f->p[1].x = x0 - 1;
  f->p[2].y = y0 + 1;
  f->p[2].x = x0;
  f->p[3].y = y0 + 2;
  f->p[3].x = x0;
}
void rotate_L_to3(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 - 1;
  f->p[1].x = x0;
  f->p[2].y = y0;
  f->p[2].x = x0 - 1;
  f->p[3].y = y0;
  f->p[3].x = x0 - 2;
}

void rotate_S_to0(struct figure* f) { init_S(f); }
void rotate_S_to1(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 - 1;
  f->p[1].x = x0;
  f->p[2].y = y0;
  f->p[2].x = x0 + 1;
  f->p[3].y = y0 + 1;
  f->p[3].x = x0 + 1;
}

void rotate_T_to0(struct figure* f) { init_T(f); }
void rotate_T_to1(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0;
  f->p[1].x = x0 - 1;
  f->p[2].y = y0 - 1;
  f->p[2].x = x0;
  f->p[3].y = y0 + 1;
  f->p[3].x = x0;
}
void rotate_T_to2(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0;
  f->p[1].x = x0 - 1;
  f->p[2].y = y0 - 1;
  f->p[2].x = x0;
  f->p[3].y = y0;
  f->p[3].x = x0 + 1;
}
void rotate_T_to3(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 - 1;
  f->p[1].x = x0;
  f->p[2].y = y0;
  f->p[2].x = x0 + 1;
  f->p[3].y = y0 + 1;
  f->p[3].x = x0;
}

void rotate_Z_to0(struct figure* f) { init_Z(f); }
void rotate_Z_to1(struct figure* f) {
  int y0 = f->p[0].y, x0 = f->p[0].x;
  f->p[1].y = y0 + 1;
  f->p[1].x = x0 - 1;
  f->p[2].y = y0;
  f->p[2].x = x0 - 1;
  f->p[3].y = y0 - 1;
  f->p[3].x = x0;
}

void rotate_I(struct figure* f) {
  switch (f->pos) {
    case 0:
      rotate_I_to0(f);
      break;
    case 1:
      rotate_I_to1(f);
      break;
  }
}

void rotate_J(struct figure* f) {
  switch (f->pos) {
    case 0:
      rotate_J_to0(f);
      break;
    case 1:
      rotate_J_to1(f);
      break;
    case 2:
      rotate_J_to2(f);
      break;
    case 3:
      rotate_J_to3(f);
      break;
  }
}

void rotate_L(struct figure* f) {
  switch (f->pos) {
    case 0:
      rotate_L_to0(f);
      break;
    case 1:
      rotate_L_to1(f);
      break;
    case 2:
      rotate_L_to2(f);
      break;
    case 3:
      rotate_L_to3(f);
      break;
  }
}

void rotate_S(struct figure* f) {
  switch (f->pos) {
    case 0:
      rotate_S_to0(f);
      break;
    case 1:
      rotate_S_to1(f);
      break;
  }
}

void rotate_T(struct figure* f) {
  switch (f->pos) {
    case 0:
      rotate_T_to0(f);
      break;
    case 1:
      rotate_T_to1(f);
      break;
    case 2:
      rotate_T_to2(f);
      break;
    case 3:
      rotate_T_to3(f);
      break;
  }
}

void rotate_Z(struct figure* f) {
  switch (f->pos) {
    case 0:
      rotate_Z_to0(f);
      break;
    case 1:
      rotate_Z_to1(f);
      break;
  }
}

void rotate_figure(struct figure* f) {
  f->pos = (f->pos + 1) % f->poses_count;
  switch (f->type) {
    case I:
      rotate_I(f);
      break;
    case J:
      rotate_J(f);
      break;
    case L:
      rotate_L(f);
      break;
    case O:
      break;
    case S:
      rotate_S(f);
      break;
    case T:
      rotate_T(f);
      break;
    case Z:
      rotate_Z(f);
      break;
  }
}

void figure_to_field(struct figure* f, struct field* fld) {
  for (int k = 0; k < 4; ++k) {
    int y = f->p[k].y;
    int x = f->p[k].x - 1;

    if (y >= 0 && y < 20 && x >= 0 && x < 10) {
      fld->points[y][x] = true;
    }
  }
}