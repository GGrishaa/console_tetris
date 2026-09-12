#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "draw.h"
#include "figure.h"
#include "manipulate.h"

int main() {
  enum TYPE r, r2;
  struct figure cur, next;
  struct field fld;
  int c;
  initialization(&cur, &next, &fld, &r, &r2);

  while ((c = getch()) != 27) {
    if (c == ' ') {
      clear();
      spawn_figure(&cur, &next, &r, &r2);
      draw_field(&cur, &next, &fld);
    } else if (c == KEY_RIGHT && can_right(&cur, &fld)) {
      clear();
      move_right_figure(&cur);
      draw_field(&cur, &next, &fld);
    } else if (c == KEY_LEFT && can_left(&cur, &fld)) {
      clear();
      move_left_figure(&cur);
      draw_field(&cur, &next, &fld);
    } else if (c == KEY_DOWN && can_down(&cur, &fld)) {
      clear();
      move_down_figure(&cur);
      draw_field(&cur, &next, &fld);
    } else if (c == KEY_DOWN && !can_down(&cur, &fld)) {
      clear();
      figure_to_field(&cur, &fld);
      check_lines(&fld);
      spawn_figure(&cur, &next, &r, &r2);
      draw_field(&cur, &next, &fld);
    } else if (c == KEY_UP && can_rot(&cur, &fld)) {
      clear();
      rotate_figure(&cur);
      draw_field(&cur, &next, &fld);
    }
  }

  endwin();
  return 0;
}