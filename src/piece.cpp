#include "Piece.h"
#include "raylib.h"

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

void Piece::MoveLeft() { col--; }
void Piece::MoveRight() { col++; }
void Piece::MoveDown() { row++; }
void Piece::MoveUp() { row--; }

void Piece::Rotate()
{
    int tmp[4][4];
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            tmp[c][3 - r] = shape[r][c];

    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            shape[r][c] = tmp[r][c];
}

bool Piece::IsFilled(int r, int c) const
{
    return shape[r][c] != 0;
}

void Piece::Draw() const
{
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            if (shape[r][c])
                DrawRectangle((col + c) * CELL_SIZE, (row + r) * CELL_SIZE,
                              CELL_SIZE, CELL_SIZE, SKYBLUE);
}