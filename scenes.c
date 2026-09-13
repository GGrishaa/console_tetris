#include "scenes.h"

int draw_welcome() {
  clear();
  mvprintw(0, 0, "        _     _  _        _");
  mvprintw(1, 0, "\\    / [_ |  /  | | |\\/| [_");
  mvprintw(2, 0, " \\/\\/  [_ [_ \\_ [_] |  | [_");
  attron(COLOR_PAIR(1));
  mvprintw(3, 8, "to tetris");
  attroff(COLOR_PAIR(1));
  mvprintw(5, 0, "press \"s\" to start the game");
  mvprintw(6, 2, "or press \"q\" to quit");
  int c = '0';
  while (c != 'q' && c != 's') {
    c = getch();
  }
  clear();
  return (c == 's');
}

void draw_end(int* sc, int* rec) {
  clear();
  mvprintw(0, 0, "___      _    _       _");
  mvprintw(1, 0, " |  |_| [_   [_ |\\ | | \\");
  mvprintw(2, 0, " |  | | [_   [_ | \\| |_/");
  mvprintw(3, 8, "score:");
  attron(COLOR_PAIR(1));
  mvprintw(4, 10, "%d", *sc);
  attroff(COLOR_PAIR(1));
  mvprintw(5, 10, "record:");
  attron(COLOR_PAIR(1));
  mvprintw(6, 10, "%d", *rec);
  attroff(COLOR_PAIR(1));
  getch();
}