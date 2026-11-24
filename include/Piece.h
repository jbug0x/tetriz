#pragma once
#include "Constants.h"
enum PieceType
{
    I,
    O,
    T,
    L,
    J,
    S,
    Z,
    Count
};

class Piece
{
public:
    Piece(PieceType type = PieceType::I);

    void Draw() const;
    void MoveUp();
    void MoveLeft();
    void MoveRight();
    void MoveDown();
    void Rotate();

    const int (&getShape() const)[4][4] { return shape; }
    const int(&getRow() const) { return row; }
    const int(&getCol() const) { return col; }

    bool IsFilled(int r, int c) const;

private:
    PieceType type;
    int row = 0;
    int col = 3;
    int shape[4][4] = {};
};