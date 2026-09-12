#include "draw.h"

void draw_figure(struct figure* f) {
  cchar_t ch_w;
  setcchar(&ch_w, L"", A_NORMAL, 0, NULL);
  for (int i = 0; i < 4; ++i) {
    mvadd_wch(f->p[i].y, f->p[i].x, &ch_w);
  }
}

void draw_field(struct figure* f, struct figure* next) {
  for (int i = 0; i < 22; ++i) {
    mvaddch(i, 12, '#');
    mvaddch(i, 0, '#');
  }
  for (int j = 0; j < 13; ++j) {
    mvaddch(21, j, '#');
  }

  mvprintw(13, 15, "next:");
  draw_figure(f);
  draw_figure(next);
}