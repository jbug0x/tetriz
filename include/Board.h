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

    int ClearFullRows();

private:
    int grid[ROWS][COLUMNS] = {};
    bool IsRowFull(int row) const;
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);

    Piece currentPiece;
};