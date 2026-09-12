#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "figure.h"

int rand_type() { return rand() % 7 + 1; }

int main() {
  srand(time(NULL));
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, true);
  setlocale(LC_ALL, "");

  enum TYPE r = rand_type();
  struct figure f;
  init_figure(&f, r, 5, 5);
  draw_figure(&f);
  int c;

  while ((c = getch()) != 27) {
    if (c == ' ') {
      clear();
      r = rand_type();
      init_figure(&f, r, 5, 5);
      draw_figure(&f);
    } else if (c == KEY_RIGHT) {
      clear();
      move_right_figure(&f);
      draw_figure(&f);
    } else if (c == KEY_LEFT) {
      clear();
      move_left_figure(&f);
      draw_figure(&f);
    } else if (c == KEY_DOWN) {
      clear();
      move_down_figure(&f);
      draw_figure(&f);
    } else if (c == KEY_UP) {
      clear();
      rotate_figure(&f);
      draw_figure(&f);
    }
  }

  endwin();
  return 0;
}