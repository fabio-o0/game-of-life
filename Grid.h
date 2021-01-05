#pragma once

#include <vector>

class Grid {
    private:
        unsigned short width, height;
        std::vector<std::vector<bool>> grid;
    public:
        Grid(unsigned short width, unsigned short height);
};
