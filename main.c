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
  int is_played = play, cycles = 80, cycle = 0;
  while (play) {
    c = getch();
    if (c == ' ') {
      cycle = 0;
      clear();
      extra_move_down(&cur, &fld);
      figure_to_field(&cur, &fld);
      check_lines(&fld, &score);
      play = spawn_figure(&cur, &next, &fld, &r, &r2);
      score += 10;
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == KEY_RIGHT && can_right(&cur, &fld)) {
      cycle = 0;
      clear();
      move_right_figure(&cur);
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == KEY_LEFT && can_left(&cur, &fld)) {
      cycle = 0;
      clear();
      move_left_figure(&cur);
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == KEY_DOWN && can_down(&cur, &fld)) {
      cycle = 0;
      clear();
      move_down_figure(&cur);
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == KEY_DOWN && !can_down(&cur, &fld)) {
      cycle = 0;
      clear();
      figure_to_field(&cur, &fld);
      check_lines(&fld, &score);
      play = spawn_figure(&cur, &next, &fld, &r, &r2);
      score += 10;
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == KEY_UP && can_rot(&cur, &fld)) {
      cycle = 0;
      clear();
      rotate_figure(&cur);
      draw_field(&cur, &next, &fld, &score, &record);
    } else if (c == ERR) {
      ++cycle;
      mvprintw(20, 20, "%d", cycle);
      if (cycle == cycles) {
        cycle = 0;
        if (can_down(&cur, &fld)) {
          move_down_figure(&cur);
          clear();
          draw_field(&cur, &next, &fld, &score, &record);
        } else {
          clear();
          figure_to_field(&cur, &fld);
          check_lines(&fld, &score);
          play = spawn_figure(&cur, &next, &fld, &r, &r2);
          score += 10;
          draw_field(&cur, &next, &fld, &score, &record);
        }
      }
    } else if (c == 27) break;
  }
  (void)is_played;
  denitialization(&score, &record);
  return 0;
}