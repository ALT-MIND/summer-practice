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
