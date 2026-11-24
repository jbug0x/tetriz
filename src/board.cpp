#include "../include/Board.h"
#include "raylib.h"

Board::Board()
{
    // grid já nasce zerado pelo "= {}"
}

bool Board::IsCellFree(int row, int col) const
{
    return grid[row][col] == 0;
}

void Board::Draw() const
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMNS; c++)
        {
            DrawRectangleLines(c * CELL_SIZE, r * CELL_SIZE, CELL_SIZE, CELL_SIZE, DARKGRAY);

            if (grid[r][c] != 0)
                DrawRectangle(c * CELL_SIZE, r * CELL_SIZE, CELL_SIZE, CELL_SIZE, WHITE);
        }
    }
}