#include "../include/config_win.h"
#include "ncurses.h"
#include <stdbool.h>
#include "stdlib.h"

board_conf config_win(){

    static int b[2] = {1, 1}, i = 0;
    int c;
    WINDOW * config = newwin(0, 0, 0, 0);
    keypad(config, TRUE);
    board_conf t;
    for (;;) {
        mvwprintw(config, LINES / 3, COLS / 3, "Рядки: %d %c ", b[0], i == 0 ? '<' : ' ');
        mvwprintw(config, LINES / 3 + 2, COLS / 3, "Стовпці: %d %c", b[1], i == 1 ? '<' : ' ');
        wrefresh(config);
        c = wgetch(config);
        switch (c) {
            case KEY_UP:
                if (i == 0){
                    if (b[i] >= 1 && b[i] < LINES / 2 - 1) b[i]++;
                }
                else if (i == 1){
                    if (b[i] >= 1 && b[i] < COLS / 4 - 1) b[i]++;
                }
                break;
            case KEY_DOWN:
                if (i == 0){
                    if (b[i] > 1 && b[i] <= LINES / 2 - 1) b[i]--;
                }
                else if (i == 1){
                    if (b[i] > 1 && b[i] <= COLS / 4 - 1) b[i]--;
                }

                break;
            case 9:
                i = !i;
                break;
            case 113: // quit
                t.row = b[0];
                t.col = b[1];
                werase(config);
                return t;
            werase(config);
        }
    }
}