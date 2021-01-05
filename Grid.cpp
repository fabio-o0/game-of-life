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

void Grid::nextGeneration() {
    std::vector<unsigned short> set;
    std::vector<unsigned short> unset;
    for (unsigned short i = 0; i < this->height; i++) {
        for (unsigned short j = 0; j < this->width; j++) {
            unsigned char neighbors = 0;
            for (char y = -1; y < 2; y++) {
                for (char x = -1; x < 2; x++) {
                    //printf("checked (%d, %d)\n", j + x, y + i);
                    if (i + y >= 0 && i + y < this->height && j + x >= 0 && j + x < this->width && !(y == 0 || x == 0) && this->values[i + y][j + x]) {
                        neighbors++;
                    }
                }
            }
            //printf("(%d, %d) has %d neighbors\n", j, i, neighbors);
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
