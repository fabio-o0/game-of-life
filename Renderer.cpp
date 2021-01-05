#include "Renderer.h"

Renderer::Renderer(Grid* grid) {
    this->grid = grid;
    this->window = initscr();
    keypad(this->window, true);
    nodelay(this->window, true);
    curs_set(0);
    cbreak();
    noecho();
    clear();
    refresh();
}

void Renderer::show() {
    for (unsigned short i = 0; i < this->grid->height; i++) {
        for (unsigned short j = 0; j < this->grid->width; j++) {
            if (this->grid->values[i][j]) mvaddch(i, j, '\xD8');
            else mvaddch(i, j, ' ');
        }
    }
    refresh();
}
