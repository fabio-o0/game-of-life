#include "Grid.h"

Grid::Grid(unsigned short width, unsigned short height) {
    this->width = width;
    this->height = height;
    this->values.resize(height);
    for (unsigned short i = 0; i < height; i++) {
        this->values[i].resize(width);
    }
}

Grid::Grid(unsigned short width, unsigned short height, unsigned char initialConfig) {
    this->width = width;
    this->height = height;
    this->values.resize(height);
    for (unsigned short i = 0; i < height; i++) {
        this->values[i].resize(width);
    }
    switch (initialConfig) {
        case 'G':
            this->set(1, 5);
            this->set(2, 5);
            this->set(1, 6);
            this->set(2, 6);
            this->set(11, 5);
            this->set(11, 6);
            this->set(11, 7);
            this->set(12, 4);
            this->set(12, 8);
            this->set(13, 3);
            this->set(13, 9);
            this->set(14, 3);
            this->set(14, 9);
            this->set(15, 6);
            this->set(16, 4);
            this->set(16, 8);
            this->set(17, 5);
            this->set(17, 6);
            this->set(17, 7);
            this->set(18, 6);
            this->set(21, 3);
            this->set(21, 4);
            this->set(21, 5);
            this->set(22, 3);
            this->set(22, 4);
            this->set(22, 5);
            this->set(23, 2);
            this->set(23, 6);
            this->set(25, 2);
            this->set(25, 6);
            this->set(25, 1);
            this->set(25, 7);
            this->set(35, 3);
            this->set(35, 4);
            this->set(36, 3);
            this->set(36, 4);
            break;
        default:
            break;
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
            if (y + dy >= 0 && y + dy < this->height && x + dx >= 0 && x + dx < this->width && !(dx == 0 || dy == 0) && this->values[y + dy][x + dx]) {
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
            unsigned char neighbors = 0;
            for (char y = -1; y < 2; y++) {
                for (char x = -1; x < 2; x++) {
                    if (i + y >= 0 && i + y < this->height && j + x >= 0 && j + x < this->width && !(y == 0 && x == 0) && this->values[i + y][j + x]) {
                        neighbors++;
                    }
                }
            }
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
