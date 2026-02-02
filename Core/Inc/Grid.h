#pragma once    

#include <vector>

class Grid {
    int x, y;
    std::vector<std::vector<int>> grid;

    public:
        Grid(int x, int y);

        void print();
};