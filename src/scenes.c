#include "scenes.h"

int draw_welcome() {
  clear();
  mvprintw(0, 0, "        _     _  _        _");
  mvprintw(1, 0, "\\    / [_ |  /  | | |\\/| [_");
  mvprintw(2, 0, " \\/\\/  [_ [_ \\_ [_] |  | [_");
  attron(COLOR_PAIR(1));
  mvprintw(3, 8, "to tetris");
  attroff(COLOR_PAIR(1));
  mvprintw(5, 0, "\"s\" to start the game");
  mvprintw(6, 0, "    \"q\" to quit");
  mvprintw(7, 0, "  \"r\" to read rules");
  int c = '0';
  while (c != 'q' && c != 's' && c != 'r') {
    c = getch();
  }
  clear();
  return c;
}

void draw_rules() {
  clear();
  mvprintw(0, 0, "      _          _  _");
  mvprintw(1, 0, "     [_} | | |  [_ (_");
  mvprintw(2, 0, "     [ \\ \\_/ [_ [_  _)");
  mvprintw(4, 0, "press \" \" to move figure left");
  mvprintw(5, 0, "press \" \" to move figure right");
  mvprintw(6, 0, "press \" \" to move figure down");
  mvprintw(7, 0, "press \" \" to rotate figure");
  mvprintw(8, 0, "press \" \" to pause");
  mvprintw(9, 0, "press \"     \" to insta move figure down");
  mvprintw(10, 0, "press \" \" to mute/unmute music (only in game)");
  mvprintw(11, 0, "press \" \" to go back");

  cchar_t ch_w;
  attron(COLOR_PAIR(1));
  setcchar(&ch_w, L"←", A_NORMAL, 0, NULL);
  mvadd_wch(4, 7, &ch_w);
  setcchar(&ch_w, L"→", A_NORMAL, 0, NULL);
  mvadd_wch(5, 7, &ch_w);
  setcchar(&ch_w, L"↓", A_NORMAL, 0, NULL);
  mvadd_wch(6, 7, &ch_w);
  setcchar(&ch_w, L"↑", A_NORMAL, 0, NULL);
  mvadd_wch(7, 7, &ch_w);
  mvaddch(8, 7, 'p');
  mvprintw(9, 7, "SPACE");
  mvaddch(10, 7, 'm');
  mvaddch(11, 7, 'q');
  attroff(COLOR_PAIR(1));
  while (getch() != 'q');
}

void draw_pause() {
  clear();
  mvprintw(0, 0, "      _   _       _   _");
  mvprintw(1, 0, "     [_) [_] | | (_  [_");
  mvprintw(2, 0, "     [   [ ] \\_/  _) [_");
  while (getch() != 'q');
}

void draw_end(int* sc, int* rec, long long* seed) {
  clear();
  mvprintw(0, 0, "___      _    _       _");
  mvprintw(1, 0, " |  |_| [_   [_ |\\ | | \\");
  mvprintw(2, 0, " |  | | [_   [_ | \\| |_/");
  mvprintw(3, 8, "score:");
  attron(COLOR_PAIR(1));
  mvprintw(4, 10, "%d", *sc);
  attroff(COLOR_PAIR(1));
  mvprintw(5, 8, "record:");
  attron(COLOR_PAIR(1));
  mvprintw(6, 10, "%d", *rec);
  attroff(COLOR_PAIR(1));
  mvprintw(7, 8, "seed: (to use it paste into seed.txt)");
  attron(COLOR_PAIR(1));
  mvprintw(8, 10, "%lld", *seed);
  attroff(COLOR_PAIR(1));
  mvprintw(9, 3, "press \"q\" to finish");
  while (getch() != 'q');
}