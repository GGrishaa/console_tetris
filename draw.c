#include "draw.h"

void draw_figure(struct figure* f) {
  cchar_t ch_w;
  setcchar(&ch_w, L"", A_NORMAL, 0, NULL);
  for (int i = 0; i < 4; ++i) {
    mvadd_wch(f->p[i].y, f->p[i].x, &ch_w);
  }
}

void draw_field(struct figure* f, struct figure* next, struct field* fld) {
  cchar_t ch_w;
  setcchar(&ch_w, L"", A_NORMAL, 0, NULL);
  for (int i = 0; i < 21; ++i) {
    mvaddch(i, 11, '#');
    mvaddch(i, 0, '#');
  }
  for (int j = 0; j < 12; ++j) {
    mvaddch(20, j, '#');
  }

  mvprintw(13, 15, "next:");
  draw_figure(f);
  draw_figure(next);
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (fld->points[i][j]) mvadd_wch(i, j + 1, &ch_w);
    }
  }
}

void spawn_figure(struct figure* cur, struct figure* next, enum TYPE* r,
                  enum TYPE* r2) {
  *r = *r2;
  *r2 = (enum TYPE)rand_type();
  init_figure(cur, *r, 0, 5);
  init_figure(next, *r2, 16, 17);
}

void initialization(struct figure* f, struct figure* next, struct field* fld,
                    enum TYPE* r, enum TYPE* r2) {
  srand(time(NULL));
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, true);
  setlocale(LC_ALL, "");
  *r = rand_type();
  *r2 = rand_type();
  init_field(fld);
  spawn_figure(f, next, r, r2);
  draw_field(f, next, fld);
}

void remove_line(struct field* fld, int n) {
  for (int i = 0; i < 10; ++i) {
    fld->points[n][i] = false;
  }
  for (int j = n; j > 0; --j) {
    for (int i = 0; i < 10; ++i) {
      fld->points[j][i] = fld->points[j - 1][i];
    }
  }
}

void check_lines(struct field* fld) {
  for (int j = 0; j < 20; ++j) {
    int filled = true;
    for (int i = 0; filled && i < 10; ++i) {
      filled = fld->points[j][i];
    }
    if (filled) remove_line(fld, j);
  }
}