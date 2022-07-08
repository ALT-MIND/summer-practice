#ifndef PRACTIS_BOARD_H
#define PRACTIS_BOARD_H
#include "ncurses.h"

void print_board(WINDOW * win, int row, int col);

void move_right(WINDOW * win, int cur_y, int * cur_x, char * update);
void move_left(WINDOW * win, int cur_y, int * cur_x, char * update);
void move_up(WINDOW * win, int * cur_y, int cur_x, char * update);
void move_down(WINDOW * win, int * cur_y, int cur_x, char * update);
int cell_is_empty(int board[], int width, int row, int col);

#endif // PRACTIS_BOARD_H