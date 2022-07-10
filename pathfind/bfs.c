#include "../include/bfs.h"
#include "../include/queue.h"

int find_patch(int board[], pos start, pos stop, int row, int col){

    pos current;
    int delta_y[] = {-1, 0, 1, 0};
    int delta_x[] = {0, 1, 0, -1};
    int q;
    cell board_clone[row][col];
    Queue * queue = create_queue(row * col);
    enqueue(queue, start);
        board_clone[start.y][start.x].visited = 'y';
        board_clone[start.y][start.x].prev_step_cell_pos.y = -1;
        board_clone[start.y][start.x].prev_step_cell_pos.x = -1;
        pos temp;
    for(;;){
        current = front(queue);
        if (current.x == -2 && current.y == -2) return 0;
        if (current.x == stop.x && current.y == stop.y) {
            cell t = board_clone[stop.y][stop.x];
            for (;;) {
                if (board_clone[t.prev_step_cell_pos.y][t.prev_step_cell_pos.x].prev_step_cell_pos.y == -1 &&
                                board_clone[t.prev_step_cell_pos.y][t.prev_step_cell_pos.x].prev_step_cell_pos.x == -1) return 1;
                board[col * t.prev_step_cell_pos.y + t.prev_step_cell_pos.x] = 2;
                t = board_clone[t.prev_step_cell_pos.y][t.prev_step_cell_pos.x];
            }
        }
        for (q = 0; q < 4; q++){
            if (current.y + delta_y[q] < 0 || current.y + delta_y[q] > row - 1) continue;
            if (current.x + delta_x[q] < 0 || current.x + delta_x[q] > col - 1) continue;
            if (board_clone[current.y + delta_y[q]][current.x + delta_x[q]].visited == 'w') {
                continue;
                }
            if (board_clone[current.y + delta_y[q]][current.x + delta_x[q]].visited == 'y') {
                continue;
            }
            if (board[col * (current.y + delta_y[q]) + (current.x + delta_x[q])] == 1){

                board_clone[current.y + delta_y[q]][current.x + delta_x[q]].visited = 'w';
                continue;

            }
            board_clone[current.y + delta_y[q]][current.x + delta_x[q]].visited = 'y';
            board_clone[current.y + delta_y[q]][current.x + delta_x[q]].prev_step_cell_pos = current;
            temp.x = current.x + delta_x[q];
            temp.y = current.y + delta_y[q];
            enqueue(queue, temp);
            
            }
        dequeue(queue);
    }
}