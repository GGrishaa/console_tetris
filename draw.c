#include "draw.h"

void draw_figure(struct figure* f) {
  attron(COLOR_PAIR(1));
  cchar_t ch_w;
  setcchar(&ch_w, L"", A_NORMAL, 0, NULL);
  for (int i = 0; i < 4; ++i) {
    mvadd_wch(f->p[i].y, f->p[i].x, &ch_w);
  }
  attroff(COLOR_PAIR(1));
}

void draw_field(struct figure* f, struct figure* next, struct field* fld,
                int* score, int* record) {
  cchar_t ch_w;
  setcchar(&ch_w, L"", A_NORMAL, 0, NULL);
  for (int i = 0; i < 21; ++i) {
    mvaddch(i, 11, '#');
    mvaddch(i, 0, '#');
  }
  for (int j = 0; j < 12; ++j) {
    mvaddch(20, j, '#');
  }

  if (*score > *record) *record = *score;
  mvprintw(13, 15, "next:");
  mvprintw(0, 15, "score:");
  mvprintw(1, 16, "%d", *score);
  mvprintw(3, 15, "record:");
  mvprintw(4, 16, "%d", *record);
  draw_figure(f);
  draw_figure(next);
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (fld->points[i][j]) mvadd_wch(i, j + 1, &ch_w);
    }
  }
}

int spawn_figure(struct figure* cur, struct figure* next, struct field* fld,
                 enum TYPE* r, enum TYPE* r2) {
  *r = *r2;
  *r2 = (enum TYPE)rand_type();
  init_figure(cur, *r, 0, 5);
  init_figure(next, *r2, 16, 17);
  return can_be(cur, fld);
}

int initialization(struct figure* f, struct figure* next, struct field* fld,
                   enum TYPE* r, enum TYPE* r2, int* score, int* record) {
  srand(time(NULL));
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, true);
  setlocale(LC_ALL, "");
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  int fl = draw_welcome();
  if (fl) {
    *r = rand_type();
    *r2 = rand_type();
    *score = 0;
    FILE* file = fopen(RECORD_FILE, "r");
    if (file == NULL)
      *record = 0;
    else
      fscanf(file, "%d", record);
    fclose(file);
    init_field(fld);
    spawn_figure(f, next, fld, r, r2);
    draw_field(f, next, fld, score, record);
  }
  return fl;
}

void denitialization(int* score, int* record) {
  draw_end(score, record);
  endwin();
  FILE* file = fopen(RECORD_FILE, "w");
  fprintf(file, "%d", *record);
  fclose(file);
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

void check_lines(struct field* fld, int* score) {
  int c = 0;
  for (int j = 0; j < 20; ++j) {
    int filled = true;
    for (int i = 0; filled && i < 10; ++i) {
      filled = fld->points[j][i];
    }
    if (filled) {
      remove_line(fld, j);
      ++c;
    }
  }
  switch (c) {
    case 1:
      *score += 100;
      break;
    case 2:
      *score += 250;
      break;
    case 3:
      *score += 400;
      break;
    case 4:
      *score += 600;
      break;
  }
}