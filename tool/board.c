#include "../include/board.h"

void print_board(WINDOW * win, int _row, int _col){
    _col *= 4;
    _row *= 2;
    for(int row = 0; row <= _row; row++){
        for(int col = 0; col <= _col; col++){
            if (row == 0){
                if (col == 0) mvwprintw(win, row + 1, col + 1, "┌");
                else if (col == _col) mvwprintw(win, row + 1, col + 1, "┐");
                else if (col % 4 == 0) mvwprintw(win,  row + 1, col + 1, "┬");
                else mvwprintw(win,  row + 1, col + 1, "─");
            }
            else if (row == _row){
                if (col == 0) mvwprintw(win, row + 1, col + 1, "└");
                else if (col == _col) mvwprintw(win, row + 1, col + 1, "┘");
                else if (col % 4 == 0) mvwprintw(win,  row + 1, col + 1, "┴");
                else mvwprintw(win,  row + 1, col + 1, "─");
            }
            else if (row % 2 == 0){
                if (col == 0) mvwprintw(win, row + 1, col + 1, "├");
                else if (col == _col) mvwprintw(win, row + 1, col + 1, "┤");
                else if (col % 4 == 0) mvwprintw(win,  row + 1, col + 1, "┼");
                else mvwprintw(win,  row + 1, col + 1, "─");
            }
            else{
                if (col == 0 || col == _col || col % 4 == 0)  mvwprintw(win, row + 1, col + 1, "│");
                else mvwprintw(win,  row + 1, col + 1, " ");
            }
        }
    }
}

void move_right(WINDOW * win, int cur_y, int * cur_x, char* update){

    if (* update == 'y') mvwaddstr(win, cur_y, *cur_x, " ");
    else *update = 'y';
    *cur_x += 4;
    mvwaddstr(win, cur_y, *cur_x, "●");
    wrefresh(win);

}

void move_left(WINDOW * win, int cur_y, int * cur_x, char * update){

    if (* update == 'y') mvwaddstr(win, cur_y, *cur_x, " ");
    else *update = 'y';
    *cur_x -= 4;
    mvwaddstr(win, cur_y, *cur_x, "●");
    wrefresh(win);

}

void move_up(WINDOW * win, int * cur_y, int cur_x, char * update){

    if (* update == 'y') mvwaddstr(win, * cur_y, cur_x, " ");
    else *update = 'y';
    *cur_y -= 2;
    mvwaddstr(win, * cur_y, cur_x, "●");
    wrefresh(win);

}

void move_down(WINDOW * win, int * cur_y, int cur_x, char * update){

    if (* update == 'y') mvwaddstr(win, * cur_y, cur_x, " ");
    else *update = 'y';
    *cur_y += 2;
    mvwaddstr(win, * cur_y, cur_x, "●");
    wmove(win, * cur_y, cur_x);
    wrefresh(win);

}

int cell_is_empty(int board[], int width, int row, int col){

    if (board[width * row + col]) return 1;
    else return 0;
        
}