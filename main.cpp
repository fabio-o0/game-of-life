#include "Renderer.h"

int main(int argv, char** argc) {
    Grid* grid = new Grid(80, 24);
    Renderer* renderer = new Renderer(grid);
    grid->set(1, 5);
    grid->set(2, 5);
    grid->set(1, 6);
    grid->set(2, 6);
    
    grid->set(11, 5);
    grid->set(11, 6);
    grid->set(11, 7);
    grid->set(12, 4);
    grid->set(12, 8);
    grid->set(13, 3);
    grid->set(13, 9);
    grid->set(14, 3);
    grid->set(14, 9);
    grid->set(15, 6);
    grid->set(16, 4);
    grid->set(16, 8);
    grid->set(17, 5);
    grid->set(17, 6);
    grid->set(17, 7);
    grid->set(18, 6);
    
    grid->set(21, 3);
    grid->set(21, 4);
    grid->set(21, 5);
    grid->set(22, 3);
    grid->set(22, 4);
    grid->set(22, 5);
    grid->set(23, 2);
    grid->set(23, 6);
    grid->set(25, 2);
    grid->set(25, 6);
    grid->set(25, 1);
    grid->set(25, 7);
    
    grid->set(35, 3);
    grid->set(35, 4);
    grid->set(36, 3);
    grid->set(36, 4);
    unsigned short count = 0;
    while (1) {
        renderer->show();
       if (count == 600) {
            count = 0;
            grid->nextGeneration();
        }
        count++;
    }
    return 0;
}
 
