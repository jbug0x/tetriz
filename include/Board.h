#pragma once
#include "Constants.h"

class Board
{
public:
    Board();

    bool IsCellFree(int row, int col) const;
    void Draw() const;

private:
    int grid[ROWS][COLUMNS] = {};
};