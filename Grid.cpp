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
    for (unsigned short i = 0; i < this->height; i++) {
        for (unsigned short j = 0; j < this->width; j++) {
            unsigned char neighbors = 0;
            for (unsigned char y = -1; y < 2; y++) {
                for (unsigned char x = -1; x < 2; x++) {
                    if (i + y >= 0 && i + y < this->height && j + x >= 0 && j + x < this->width && i + y != 0 && j + x != 0 && this->values[i + y][j + x]) {
                        neighbors++;
                    }
                }
            }
            printf("%d", neighbors);
            if (this->values[i][j] && neighbors != 2 && neighbors != 3) {
                this->unset(j, i);
            }
            else if (!this->values[i][j] && neighbors == 3) {
                this->set(j, i);    
            }
        }
    }
}
