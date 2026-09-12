#ifndef MANIPULATE_H
#define MANIPULATE_H

#include <ncurses.h>

#include "figure.h"

void move_left_figure(struct figure* f);
void move_right_figure(struct figure* f);
void move_down_figure(struct figure* f);
void move_up_figure(struct figure* f);
void extra_move_down(struct figure* f, struct field* fld);

void rotate_I_to0(struct figure* f);
void rotate_I_to1(struct figure* f);
void rotate_I(struct figure* f);

void rotate_J_to0(struct figure* f);
void rotate_J_to1(struct figure* f);
void rotate_J_to2(struct figure* f);
void rotate_J_to3(struct figure* f);
void rotate_J(struct figure* f);

void rotate_L_to0(struct figure* f);
void rotate_L_to1(struct figure* f);
void rotate_L_to2(struct figure* f);
void rotate_L_to3(struct figure* f);
void rotate_L(struct figure* f);

void rotate_S_to0(struct figure* f);
void rotate_S_to1(struct figure* f);
void rotate_S(struct figure* f);

void rotate_T_to0(struct figure* f);
void rotate_T_to1(struct figure* f);
void rotate_T_to2(struct figure* f);
void rotate_T_to3(struct figure* f);
void rotate_T(struct figure* f);

void rotate_Z_to0(struct figure* f);
void rotate_Z_to1(struct figure* f);
void rotate_Z(struct figure* f);

void rotate_figure(struct figure* f);

void figure_to_field(struct figure* f, struct field* fld);

#endif