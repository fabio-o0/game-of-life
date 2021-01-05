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

unsigned char Grid::getNeighborCount(unsigned short x, unsigned short y) {
    unsigned char neighbors = 0;
    for (char dy = -1; dy < 2; dy++) {
        for (char dx = -1; dx < 2; dx++) {
            if (y + dy >= 0 && y + dy < this->height && x + dx >= 0 && x + dx < this->width && !(dy == 0 && dx == 0) && this->values[y + dy][x + dx]) {
                neighbors++;
            }
        }
    }
    return neighbors;
}

void Grid::nextGeneration() {
    std::vector<unsigned short> set;
    std::vector<unsigned short> unset;
    for (unsigned short i = 0; i < this->height; i++) {
        for (unsigned short j = 0; j < this->width; j++) {
            unsigned char neighbors = this->getNeighborCount(j, i);
            if (this->values[i][j] && neighbors != 2 && neighbors != 3) {
                unset.push_back(j);
                unset.push_back(i);
            }
            else if (!this->values[i][j] && neighbors == 3) {
                set.push_back(j);
                set.push_back(i);
            }
        }
    }
    for (unsigned short i = 0; i < set.size(); i += 2) {
        this->set(set[i], set[i + 1]);
    }
    for (unsigned short i = 0; i < unset.size(); i += 2) {
        this->unset(unset[i], unset[i + 1]);
    }
}

