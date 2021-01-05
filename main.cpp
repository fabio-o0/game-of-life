#include "Renderer.h"

int main(int argv, char** argc) {
    Grid* grid = new Grid(80, 24);
    Renderer* renderer = new Renderer(grid);
    grid->set(30, 18);
    grid->set(30, 19);
    grid->set(30, 17);
    unsigned int count = 0;
    while (1) {
        if (count == 6000) {
            count = 0;
            grid->nextGeneration();
        }
        renderer->show();
        count++;
    }
    return 0;
}


