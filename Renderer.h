#pragma once

#include <ncurses.h>

#include "Grid.h"

class Renderer {
    public:
        Grid* grid;
        std::vector< std::vector<bool> > initialState;
        WINDOW* window;
        Renderer(Grid* grid);
        void show();
        void handleInput(bool &condition);
};
