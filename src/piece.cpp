#include "Piece.h"

static const int SHAPES[7][4][4] = {
    // I
    {{0, 0, 0, 0},
     {1, 1, 1, 1},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    // O
    {{0, 1, 1, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    // T
    {{0, 1, 0, 0},
     {1, 1, 1, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    // L
    {{0, 1, 0, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    // J
    {{0, 1, 0, 0},
     {1, 1, 0, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    // S
    {{0, 1, 1, 0},
     {1, 1, 0, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    // Z
    {{1, 1, 0, 0},
     {0, 1, 1, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
};

Piece::Piece(PieceType type) : type(type)
{
    int index = static_cast<int>(type); // convertendo para int

    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            shape[r][c] = SHAPES[index][r][c];
}

void Piece::Move(int dRow, int dCol)
{
    row += dRow;
    col += dCol;
}

void Piece::Rotate()
{
    if (type == PieceType::O)
        return;

    int n = (type == PieceType::I) ? 4 : 3;

    int tmp[4][4] = {};

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            tmp[c][n - 1 - r] = shape[r][c];
        }
    }

    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            shape[r][c] = tmp[r][c];
        }
    }
}

void Piece::UndoRotate()
{
    if (type == PieceType::O)
        return;

    int n = (type == PieceType::I) ? 4 : 3;
    int tmp[4][4] = {};

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            tmp[n - 1 - c][r] = shape[r][c];
        }
    }

    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            shape[r][c] = tmp[r][c];
        }
    }
}

void Piece::Draw() const
{
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            if (shape[r][c])
                DrawRectangle((col + c) * CELL_SIZE, (row + r) * CELL_SIZE,
                              CELL_SIZE, CELL_SIZE, SKYBLUE);
}