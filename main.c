#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "draw.h"
#include "figure.h"
#include "manipulate.h"

int rand_type() { return rand() % 7 + 1; }

int main() {
  srand(time(NULL));
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, true);
  setlocale(LC_ALL, "");

  enum TYPE r = rand_type(), r2 = rand_type();
  struct figure f, next;
  init_figure(&f, r, 0, 5);
  init_figure(&next, r2, 16, 17);
  draw_field(&f, &next);
  int c;

  while ((c = getch()) != 27) {
    if (c == ' ') {
      clear();
      r = r2;
      r2 = rand_type();
      init_figure(&f, r, 0, 5);
      init_figure(&next, r2, 16, 17);
      draw_field(&f, &next);
    } else if (c == KEY_RIGHT && max_right(&f) < 11) {
      clear();
      move_right_figure(&f);
      draw_field(&f, &next);
    } else if (c == KEY_LEFT && max_left(&f) > 1) {
      clear();
      move_left_figure(&f);
      draw_field(&f, &next);
    } else if (c == KEY_DOWN && max_down(&f) < 20) {
      clear();
      move_down_figure(&f);
      draw_field(&f, &next);
    } else if (c == KEY_UP) {
      clear();
      rotate_figure(&f);
      draw_field(&f, &next);
    }
  }

  endwin();
  return 0;
}