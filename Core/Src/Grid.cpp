#include "Grid.h"

#include <iostream>

Grid::Grid(int x, int y) : x(x), y(y), grid(x, std::vector<int>(y, 0)) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            grid[i][j] = 0;
        }
    }
}

void Grid::print() {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}