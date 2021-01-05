#include "Renderer.h"

int main(int argv, char** argc) {
    Grid* grid = new Grid(80, 22, 'G');
    Renderer* renderer = new Renderer(grid);
    unsigned long long count = 0;
    bool started = false;
    while (1) {
        renderer->show();
        renderer->handleInput(started);
        while (started) {
            if (count == 600) {
                count = 0;
                grid->nextGeneration();
            }
            renderer->show();
            renderer->handleInput(started);
            count++;
        }
    }
    return 0;
}
