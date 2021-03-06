#pragma once

#include <vector>

class Grid {
    public:
        unsigned short width, height;
        std::vector< std::vector<bool> > values;
        Grid(unsigned short width, unsigned short height);
        Grid(unsigned short width, unsigned short height, unsigned char initalConfig);
        void nextGeneration();
        void set(unsigned short x, unsigned short y);
        void unset(unsigned short x, unsigned short y);
        unsigned char getNeighborCount(unsigned short x, unsigned short y);
};
