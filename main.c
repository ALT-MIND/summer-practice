#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include "locale.h"
#include "include/board.h"
#include "include/queue.h"
#include "include/bfs.h"
#include "include/config_win.h"
#include "include/error_win.h"
#include "include/help_win.h"

int main(){

     int pos_y = 1, pos_x = 2, cur_row = 0, cur_col = 0, choose, i, t;
     board_conf board_cfg;
     pos start, stop;    
     start.x = -999;
     start.y = -999;
     stop.x = -999;
     stop.y = -999;

     setlocale(LC_ALL, "");
     initscr();
     cbreak();
     noecho();
     curs_set(0);
     WINDOW * main = newwin(0, 0, 0, 0);
     keypad(main, TRUE);
     
     board_cfg = config_win();
     int * board = malloc(sizeof(int) * (board_cfg.row * board_cfg.col));
     for(i = 0; i < board_cfg.col * board_cfg.row; i++){
            board[i] = 0;
        }
     print_board(main, board_cfg.row, board_cfg.col);
     mvwaddstr(main, pos_y, pos_x, "○");
     wrefresh(main);

     for (;;){

         choose = wgetch(main);
         switch (choose) {

            case 9: // TAB
                board_cfg = config_win();
                free(board);
                board = malloc(sizeof(int) * (board_cfg.row * board_cfg.col));
                for(i = 0; i < board_cfg.col * board_cfg.row; i++){
                    board[i] = 0;
                 }
                cur_col =  cur_row = 0;
                pos_y = 1;
                pos_x = 2;
                werase(main);
                print_board(main, board_cfg.row, board_cfg.col);
                mvwaddstr(main, pos_y, pos_x, "○");
                start.x = -999;
                start.y = -999;
                stop.x = -999;
                stop.y = -999;
                wrefresh(main);
                break;
            case 113: // q
                return 0;

            case 104: // h
                help_win();
                werase(main);
                print_board(main, board_cfg.row, board_cfg.col);
                restore_element(main, board, board_cfg.row, board_cfg.col);
                mvwaddstr(main, pos_y, pos_x, "○");
                wrefresh(main);
                break;

            case 99: // c
                for(i = 0; i < board_cfg.col * board_cfg.row; i++){
                    board[i] = 0;
                }
                cur_col =  cur_row = 0;
                pos_y = 1;
                pos_x = 2;
                print_board(main, board_cfg.row, board_cfg.col);
                mvwaddstr(main, pos_y, pos_x, "○");
                start.x = -999;
                start.y = -999;
                stop.x = -999;
                stop.y = -999;
                break;

            case 115: // s
                start.x = cur_col;
                start.y = cur_row;
                board[board_cfg.col * cur_row + cur_col] = 3;
                break;

            case 102: //f
                stop.x = cur_col;
                stop.y = cur_row;
                board[board_cfg.col * cur_row + cur_col] = 4;
                break;

            case 112: // p
                if (start.x == -999 || start.y == -999){
                    error_win(1);
                    werase(main);
                    print_board(main, board_cfg.row, board_cfg.col);
                    restore_element(main, board, board_cfg.row, board_cfg.col);
                    mvwaddstr(main, pos_y, pos_x, "○");
                    wrefresh(main);
                    break;
                }
                else if (stop.x == -999 || stop.y == -999) {
                    error_win(2);
                    werase(main);
                    print_board(main, board_cfg.row, board_cfg.col);
                    restore_element(main, board, board_cfg.row, board_cfg.col);
                    mvwaddstr(main, pos_y, pos_x, "○");
                    wrefresh(main);
                    break;
                }
                if(!find_patch(board, start, stop, board_cfg.row, board_cfg.col)){
                    error_win(0);
                    werase(main);
                    print_board(main, board_cfg.row, board_cfg.col);
                    restore_element(main, board, board_cfg.row, board_cfg.col);
                    mvwaddstr(main, pos_y, pos_x, "○");
                    wrefresh(main);
                    break;
                }
                werase(main);
                print_board(main, board_cfg.row, board_cfg.col);
                restore_element(main, board, board_cfg.row, board_cfg.col);
                mvwaddstr(main, pos_y, pos_x, "○");
                wrefresh(main);
                break;

            case 10: // ENTER
                board[board_cfg.col * cur_row + cur_col] = !board[board_cfg.col * cur_row + cur_col];
                break;

            case KEY_RIGHT:
               if (cur_col != board_cfg.col - 1) {
                   move_right(main, board, board_cfg.col, cur_row, cur_col, pos_y, &pos_x);
                   cur_col++;
               }
               break;

            case KEY_LEFT:
                if (cur_col != 0) {
                    move_left(main, board, board_cfg.col, cur_row, cur_col, pos_y, &pos_x);
                    cur_col--;
                } 
                break;

            case KEY_UP:
                if (cur_row != 0) {
                    move_up(main, board, board_cfg.col, cur_row, cur_col, &pos_y, pos_x);
                    cur_row--;
                }
                break;

            case KEY_DOWN:
                if (cur_row != board_cfg.row - 1) {
                    move_down(main, board, board_cfg.col, cur_row, cur_col, &pos_y, pos_x);
                    cur_row++;
                }
                break;
         }
    }
    endwin();
}
