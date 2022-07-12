#ifndef PRACTIS_CONFIG_WIN_H
#define PRACTIS_CONFIG_WIN_H

typedef struct{
    int row; 
    int col;
    float chance;
}board_conf;

board_conf config_win();

#endif // PRACTIS_CONFIG_WIN_H