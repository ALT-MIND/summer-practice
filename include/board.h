#ifndef PRACTIS_BOARD_H
#define PRACTIS_BOARD_H
#include "ncurses.h"

void print_board(WINDOW * win, int row, int col);

void move_right(WINDOW * win, int board[], int width, int row, int col, int cur_y, int * cur_x);
void move_left(WINDOW * win, int board[], int width, int row, int col, int cur_y, int * cur_x);
void move_up(WINDOW * win, int board[], int width, int row, int col,int * cur_y, int cur_x);
void move_down(WINDOW * win, int board[], int width, int row, int col, int * cur_y, int cur_x);
void restore_element(WINDOW * win, int board[], int row, int col);
int cell_is_empty(int board[], int width, int row, int col);
int is_path(int board[], int width, int row, int col);
int is_start(int board[], int width, int row, int col);
int is_stop(int board[], int width, int row, int col);

#endif // PRACTIS_BOARD_H