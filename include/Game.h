#pragma once
#include "raylib.h"
#include "Board.h"
#include "Piece.h"

class Game
{
public:
    Game(int width, int height);
    ~Game();

    void Init();
    void Update();
    void Draw();
    void Run();
    void DrawSidePanel() const;

private:
    int screenWidth;
    int screenHeight;
    int score = 0;

    float fallTimer = 0.0f;
    float fallDelay = 1.0f;

    Board board;
    Piece currentPiece = static_cast<PieceType>(GetRandomValue(0, 6));
    Piece nextPiece;

    void DrawNextPiece(const Piece &piece) const;
};