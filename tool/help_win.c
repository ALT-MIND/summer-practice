#include "ncurses.h"

void help_win(){

    WINDOW * help = newwin(12, 50, LINES / 4, COLS / 4);
    box(help, 0, 0);
    mvwprintw(help, 1, 1, "q - Вихід");
    mvwprintw(help, 2, 1, "p - Знайти шлях");
    mvwprintw(help, 3, 1, "s - Стартова точка");
    mvwprintw(help, 4, 1, "f - Кінцева точка");
    mvwprintw(help, 5, 1, "c - Очистити поле");
    mvwprintw(help, 6, 1, "h - Відкрити справку");
    mvwprintw(help, 7, 1, "ENTER - Поставити кульку, повторно - прибрати");
    mvwprintw(help, 8, 1, "TAB - Відкрити конфігуратор");
    mvwprintw(help, 10, 6, "Press any key to continue...");
    wrefresh(help);
    wgetch(help);
}