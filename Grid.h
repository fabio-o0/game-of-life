#pragma once

#include <vector>

class Grid {
    public:
        unsigned short width, height;
        std::vector< std::vector<bool> > values;
        Grid(unsigned short width, unsigned short height);
        void nextGeneration();
        void set(unsigned short x, unsigned short y);
        void unset(unsigned short x, unsigned short y);
};
