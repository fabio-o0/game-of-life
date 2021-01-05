#include "Renderer.h"

Renderer::Renderer(Grid* grid) {
    std::copy(grid->values.begin(), grid->values.end(), back_inserter(this->initialState));
    this->grid = grid;
    this->window = initscr();
    keypad(this->window, true);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
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
    for (unsigned short i = 0; i < this->grid->width; i++) {
        mvaddch(this->grid->height, i, '-');
    }
    unsigned short y = this->grid->height + 1;
    unsigned short x = 0;
    const char* menu = "Click to change cells. Press (p) to play. Press (s) to stop. Press (r) to reset.";
    for (; x < 80; x++) {
        mvaddch(y, x, menu[x]);
    }
    refresh();
}

void Renderer::handleInput(bool &condition) {
    int c;
    MEVENT e;
    
    c = wgetch(this->window);
    switch (c) {
        case KEY_MOUSE:
            if (getmouse(&e) == OK && !condition) {
                if (e.bstate) {
                    this->grid->values[e.y][e.x] = !this->grid->values[e.y][e.x];
                }
            }
            break;
        case 'p':
            condition = true;
            break;
        case 's':
            condition = false;
            break;
        case 'r':
            this->grid->values = this->initialState;
            condition = false;
            break;
        default:
            break;
    }
}
