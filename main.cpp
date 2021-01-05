#include "Renderer.h"

int main(int argv, char** argc) {
    Grid* grid = new Grid(80, 24);
    Renderer* renderer = new Renderer(grid);
    grid->set(30, 18);
    grid->set(30, 19);
    grid->set(30, 17);
    unsigned long long count = 0;
    while (1) {
        if (count == 6000) {
            count = 0;
            grid->nextGeneration();
        }
        renderer->show();
        count++;
    }
//    for (unsigned short i = 0; i < grid->height; i++) {
//        for (unsigned short j = 0; j < grid->width; j++) {
//            unsigned char neighbors = 0;
//            for (char y = -1; y < 2; y++) {
//                for (char x = -1; x < 2; x++) {
//                    //printf("checked (%d, %d)\n", j + x, y + i);
//                    if (i + y >= 0 && i + y < grid->height && j + x >= 0 && j + x < grid->width && !(y == 0 && x == 0) && grid->values[i + y][j + x]) {
//                        neighbors++;
//                    }
//                }
//            }
//            printf("(%d, %d) has %d neighbors\n", j, i, neighbors);
//            if (grid->values[i][j] && neighbors != 2 && neighbors != 3) {
//                grid->unset(j, i);
//            }
//            else if (!grid->values[i][j] && neighbors == 3) {
//                grid->set(j, i);    
//            }
//        }
//    }
    return 0;
}


