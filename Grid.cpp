#include "Grid.h"

Grid::Grid(unsigned short width, unsigned short height) {
    this->width = width;
    this->height = height;
    this->values.resize(height);
    for (unsigned short i = 0; i < height; i++) {
        this->values[i].resize(width);
    }
}

void Grid::set(unsigned short x, unsigned short y) {
    this->values[y][x] = true;
}

void Grid::unset(unsigned short x, unsigned short y) {
    this->values[y][x] = false;
}
