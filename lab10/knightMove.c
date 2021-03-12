/*

a8 b8 c8 d8 e8 f8 g8 h8
a7 b7 c7 d7 e7 f7 g7 h7
a6 b6 c6 d6 e6 f6 g6 h6
a5 b5 c5 d5 e5 f5 g5 h5
a4 b4 c4 d4 e4 f4 g4 h4
a3 b3 c3 d3 e3 f3 g3 h3
a2 b2 c2 d2 e2 f2 g2 h2
a1 b1 c1 d1 e1 f1 g1 h1


./knight_moves d4 b3
d4 b3 
./knight_moves d4 a1
d4 b3 a1
d4 c2 a1
./knight_moves g2 b2
g2 e1 d3 b2
g2 e3 c4 b2
g2 e3 d1 b2
g2 f4 d3 b2
*/

#include <stdio.h>
#include <assert.h>

#define BOARD_SIZE 8

int column_delta[] = {-2, -2, -1, -1,  1,  1,  2,  2};
int row_delta[]    = {-1,  1, -2,  2, -2,  2, -1,  1};

int print_moves(int max_path_length, int finish_column, int finish_row, 
int path_length, int path[][2]) {
    int last_column = path[path_length - 1][0];
    int last_row = path[path_length - 1][1];
    if (last_column == finish_column && last_row == finish_row) {
        assert(path_length ==  max_path_length);
        for (int p = 0; p < path_length; p++) {
            printf("%c%c", 'a'+path[p][0], '1'+path[p][1]);
            if (p != path_length - 1)
                printf(" ");
        }
        printf("\n");
        return 1;
    }

    if (path_length == max_path_length) {
        return 0;
    }

    int paths_found = 0;
    for (int m = 0 ; m < 8; m++) {
        int new_column =  last_column + column_delta[m];
        int new_row = last_row + row_delta[m];
        if (new_column >= 0 && new_column < BOARD_SIZE && new_row >= 0 && new_row < BOARD_SIZE) {
            int p;
            for (p = 0; p < path_length; p++) {
                if (path[p][0] == new_column && path[p][1] == new_row)
                    break;
            }
            if (p == path_length) {
                path[path_length][0] = new_column;
                path[path_length][1] = new_row;
                paths_found += print_moves(max_path_length, finish_column, finish_row, path_length + 1, path);
            }
        }
    }
    return paths_found;
}

int main(int argc, char *argv[]) {
    // The program will produce error code if there's 3 inputs.
    assert(argc == 3);
    int start_column = argv[1][0] - 'a';
    int start_row = argv[1][1] - '1';
    assert(0 <= start_column && start_column < BOARD_SIZE);
    assert(0 <= start_row && start_row < BOARD_SIZE);

    int finish_column = argv[2][0] - 'a';
    int finish_row = argv[2][1] - '1';
    assert(0 <= finish_column && finish_column < BOARD_SIZE);
    assert(0 <= finish_row && finish_row < BOARD_SIZE);

    for (int path_length = 1; ;path_length++) {
        int path[path_length][2];
        path[0][0] = start_column;
        path[0][1] = start_row;
        if (print_moves(path_length, finish_column, finish_row, 1, path))
            break;
    }
    return 0;
}