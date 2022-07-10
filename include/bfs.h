#ifndef PRACTIS_BFS_H
#define PRACTIS_BFS_H

typedef struct{
    int x;
    int y;
} pos;

typedef struct{
    char visited;
    pos prev_step_cell_pos;
}cell;

int find_patch(int board[], pos start, pos stop, int row, int col);

#endif // PRACTIS_BFS_H