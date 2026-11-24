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

void Board::LockPiece(const Piece &p)
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (p.getShape()[r, c] != 0)
            {
                int boardRow = p.getRow() + r;
                int boardCol = p.getCol() + c;

                if (boardRow >= 0 && boardRow < ROWS && boardCol >= 0 && boardCol < COLUMNS)
                {
                    grid[boardRow][boardCol] = 1;
                }
            }
        }
    }
}

bool Board::IsValid(const Piece &p) const
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (p.getShape()[r, c] == 0)
                continue;

            int boardRow = p.getRow() + r;
            int boardCol = p.getCol() + c;

            if (boardCol < 0 || boardCol >= COLUMNS || boardRow >= ROWS)
                return false;

            if (boardRow >= 0 && !IsCellFree(boardRow, boardCol))
                return false;
        }
    }

    return true;
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