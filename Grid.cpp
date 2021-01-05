#include "Grid.h"

Grid::Grid(unsigned short width, unsigned short height) {
    this->width = width;
    this->height = height;
    this->grid.resize(height);
    for (unsigned short i = 0; i < height; i++) {
        this->grid[i].resize(width);
    }
}
