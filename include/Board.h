#pragma once
#include "Constants.h"
#include "Piece.h"
#include "raylib.h"

class Board
{
public:
    Board();

    bool IsCellFree(int row, int col) const;
    bool IsValid(const Piece &p) const;

    void LockPiece(const Piece &p);
    void Draw() const;

private:
    int grid[ROWS][COLUMNS] = {};
    Piece currentPiece;
};