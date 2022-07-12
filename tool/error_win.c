#include "../include/error_win.h"
#include "ncurses.h"

void error_win(int err_code){
    
    char * message[3] = {
        "Шлях не знайдено",
        "Початкова точка не вказана",
        "Кінцева точка не вказана"
    };
    WINDOW * error = newwin(10, 40, LINES / 4, COLS / 4);
    box(error, 0, 0);
    mvwprintw(error, 3, 6, "%s", message[err_code]);
    mvwprintw(error, 8, 6, "Press any key to continue...");
    wrefresh(error);
    wgetch(error);
}