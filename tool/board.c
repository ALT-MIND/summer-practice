#include "../include/board.h"
#include <curses.h>

void print_board(WINDOW * win, int _row, int _col){
    _col *= 4;
    _row *= 2;
    for(int row = 0; row <= _row; row++){
        for(int col = 0; col <= _col; col++){
            if (row == 0){
                if (col == 0) mvwprintw(win, row , col , "┌");
                else if (col == _col) mvwprintw(win, row , col , "┐");
                else if (col % 4 == 0) mvwprintw(win,  row , col , "┬");
                else mvwprintw(win,  row , col , "─");
            }
            else if (row == _row){
                if (col == 0) mvwprintw(win, row , col , "└");
                else if (col == _col) mvwprintw(win, row , col , "┘");
                else if (col % 4 == 0) mvwprintw(win,  row , col , "┴");
                else mvwprintw(win,  row , col , "─");
            }
            else if (row % 2 == 0){
                if (col == 0) mvwprintw(win, row , col , "├");
                else if (col == _col) mvwprintw(win, row , col , "┤");
                else if (col % 4 == 0) mvwprintw(win,  row , col , "┼");
                else mvwprintw(win,  row , col , "─");
            }
            else{
                if (col == 0 || col == _col || col % 4 == 0)  mvwprintw(win, row , col , "│");
                else mvwprintw(win,  row , col , " ");
            }
        }
    }
}

void move_right(WINDOW * win, int * board, int width, int row, int col, int cur_y, int * cur_x){

    if (cell_is_empty(board, width, row, col)){ 
        mvwaddstr(win, cur_y, *cur_x, " ");
    }
    else if (is_path(board, width, row, col)) {
        mvwaddstr(win, cur_y, *cur_x, "+");
    }
    else if (is_start(board, width, row, col)) {
        mvwaddstr(win, cur_y, *cur_x, "Ⓢ");
    }
    else if (is_stop(board, width, row, col)) {
        mvwaddstr(win, cur_y, *cur_x, "Ⓕ");
    }
    else {
        mvwaddstr(win, cur_y, *cur_x, "●");
    }
    *cur_x += 4;
    mvwaddstr(win, cur_y, *cur_x, "○");
    wrefresh(win);

}

void move_left(WINDOW * win, int * board, int width, int row, int col, int cur_y, int * cur_x){

    if (cell_is_empty(board, width, row, col)){ 
        mvwaddstr(win, cur_y, * cur_x, " ");
    }
    else if (is_path(board, width, row, col)) {
        mvwaddstr(win, cur_y, * cur_x, "+");
    }
    else if (is_start(board, width, row, col)) {
        mvwaddstr(win, cur_y, * cur_x, "Ⓢ");
    }
    else if (is_stop(board, width, row, col)) {
        mvwaddstr(win, cur_y, * cur_x, "Ⓕ");
    }
    else {
        mvwaddstr(win, cur_y, * cur_x, "●");
    }
    *cur_x -= 4;
    mvwaddstr(win, cur_y, *cur_x, "○");
    wrefresh(win);

}

void move_up(WINDOW * win, int * board, int width, int row, int col, int * cur_y, int cur_x){

    if (cell_is_empty(board, width, row, col)){ 
        mvwaddstr(win, *cur_y, cur_x, " ");
    }
    else if (is_path(board, width, row, col)) {
        mvwaddstr(win, *cur_y, cur_x, "+");
    }
    else if (is_start(board, width, row, col)) {
        mvwaddstr(win, *cur_y, cur_x, "Ⓢ");
    }
    else if (is_stop(board, width, row, col)) {
        mvwaddstr(win, *cur_y, cur_x, "Ⓕ");
    }
    else {
        mvwaddstr(win, *cur_y, cur_x, "●");
    }
    *cur_y -= 2;
    mvwaddstr(win, * cur_y, cur_x, "○");
    wrefresh(win);

}

void move_down(WINDOW * win, int * board, int width, int row, int col, int * cur_y, int cur_x){

    if (cell_is_empty(board, width, row, col)){ 
        mvwaddstr(win, * cur_y, cur_x, " ");
    }
    else if (is_path(board, width, row, col)) {
        mvwaddstr(win, * cur_y, cur_x, "+");
    }
    else if (is_start(board, width, row, col)) {
        mvwaddstr(win, * cur_y, cur_x, "Ⓢ");
    }
    else if (is_stop(board, width, row, col)) {
        mvwaddstr(win, * cur_y, cur_x, "Ⓕ");
    }
    else {
        mvwaddstr(win, * cur_y, cur_x, "●");
    }
    *cur_y += 2;
    mvwaddstr(win, * cur_y, cur_x, "○");
    wmove(win, * cur_y, cur_x);
    wrefresh(win);

}

void restore_element(WINDOW * win, int * board, int row, int col){
    for (int y = 0; y < row; y++){
        for (int x = 0; x < col; x++){
            if (cell_is_empty(board, col, y, x)){ 
                mvwaddstr(win, y * 2 + 1, x * 4 + 2, " ");
             }
            else if (is_path(board, col, y, x)) {
                mvwaddstr(win, y * 2 + 1, x * 4 + 2 , "+");
            }
            else if (is_start(board, col, y, x)) {
                mvwaddstr(win, y * 2 + 1, x * 4 + 2, "Ⓢ");
            }
            else if (is_stop(board, col, y, x)) {
                mvwaddstr(win, y * 2 + 1, x * 4 + 2, "Ⓕ");
            }
            else {
                mvwaddstr(win, y * 2 + 1, x * 4 + 2, "●");
            }
        }
    }
}

int cell_is_empty(int * board, int width, int row, int col){

    if (board[width * row + col] == 0) return 1;
    else return 0;
        
}

int is_path(int * board, int width, int row, int col){

    if (board[width * row + col] == 2) return 1;
    else return 0;
}

int is_start(int * board, int width, int row, int col){

    if (board[width * row + col] == 3) return 1;
    else return 0;
}

int is_stop(int * board, int width, int row, int col){

    if (board[width * row + col] == 4) return 1;
    else return 0;
}