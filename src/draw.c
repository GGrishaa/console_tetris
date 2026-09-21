#include "draw.h"

void draw_figure(struct figure* f) {
  attron(COLOR_PAIR(1));
  cchar_t ch_w;
  setcchar(&ch_w, L"", A_NORMAL, 0, NULL);
  for (int i = 1; i < 4; ++i) {
    mvadd_wch(f->p[i].y, f->p[i].x, &ch_w);
  }
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(3));
  mvadd_wch(f->p[0].y, f->p[0].x, &ch_w);
  attroff(COLOR_PAIR(3));
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
  attron(COLOR_PAIR(2));
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (fld->points[i][j]) mvadd_wch(i, j + 1, &ch_w);
    }
  }
  attroff(COLOR_PAIR(2));
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (!fld->points[i][j]) mvaddch(i, j + 1, '.');
    }
  }
  draw_figure(f);
  draw_figure(next);
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
                   enum TYPE* r, enum TYPE* r2, int* score, int* record,
                   long long* seed) {
  *seed = time(NULL);
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, true);
  timeout(30);
  setlocale(LC_ALL, "");
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  *score = 0;
  *record = 0;
  int ans = draw_welcome();
  while (ans != 's' && ans != 'q') {
    draw_rules();
    ans = draw_welcome();
  }
  FILE* file1 = fopen(RECORD_FILE, "r");
  if (file1 == NULL || fscanf(file1, "%d", record) != 1) *record = 0;
  if (file1) fclose(file1);
  long long temp;
  FILE* file2 = fopen(SEED_FILE, "r");
  if (file2 != NULL && fscanf(file2, "%lld", &temp) == 1) *seed = temp;
  if (file2) fclose(file2);
  srand(*seed);
  if (ans == 's') {
    *r = rand_type();
    *r2 = rand_type();
    init_field(fld);
    spawn_figure(f, next, fld, r, r2);
    draw_field(f, next, fld, score, record);
  }
  return (ans == 's');
}

void denitialization(int* score, int* record, long long* seed) {
  draw_end(score, record, seed);
  endwin();
  FILE* file1 = fopen(RECORD_FILE, "w");
  fprintf(file1, "%d", *record);
  fclose(file1);
  FILE* file2 = fopen(SEED_FILE, "w");
  fclose(file2);
}

void remove_line(struct field* fld, int n) {
  for (int j = n; j > 0; --j) {
    for (int i = 0; i < 10; ++i) {
      fld->points[j][i] = fld->points[j - 1][i];
    }
  }
  for (int i = 0; i < 10; ++i) {
    fld->points[0][i] = false;
  }
}

void check_lines(struct field* fld, int* score, int* cycles,
                 int* final_cycles) {
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
  for (; c > 0; --c) {
    if (*cycles > *final_cycles + 3) *cycles -= 3;
  }
}