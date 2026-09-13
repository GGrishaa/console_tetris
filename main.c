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
  int c, score, record,
      play = initialization(&cur, &next, &fld, &r, &r2, &score, &record);

  while (play && (c = getch()) != 27) {
    if (c == ' ') {
      clear();
      extra_move_down(&cur, &fld);
      figure_to_field(&cur, &fld);
      check_lines(&fld, &score);
      play = spawn_figure(&cur, &next, &fld, &r, &r2);
      score += 10;
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == KEY_RIGHT && can_right(&cur, &fld)) {
      clear();
      move_right_figure(&cur);
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == KEY_LEFT && can_left(&cur, &fld)) {
      clear();
      move_left_figure(&cur);
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == KEY_DOWN && can_down(&cur, &fld)) {
      clear();
      move_down_figure(&cur);
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == KEY_DOWN && !can_down(&cur, &fld)) {
      clear();
      figure_to_field(&cur, &fld);
      check_lines(&fld, &score);
      play = spawn_figure(&cur, &next, &fld, &r, &r2);
      score += 10;
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == KEY_UP && can_rot(&cur, &fld)) {
      clear();
      rotate_figure(&cur);
      draw_field(&cur, &next, &fld, &score, &record);
    }
  }
  denitialization(&score, &record);
  return 0;
}