#pragma once

#include <ncurses.h>

#include "Grid.h"

class Renderer {
    public:
        Grid* grid;
        WINDOW* window;
        Renderer(Grid* grid);
        void show();
};
