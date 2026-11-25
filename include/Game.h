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
    bool gameOver = false;
    int screenWidth;
    int screenHeight;
    int score = 0;

    float fallTimer = 0.0f;
    float fallDelay = 0.5f;
    float softDropDelay = 0.05f;

    Board board;
    Piece currentPiece = static_cast<PieceType>(GetRandomValue(0, 6));
    Piece nextPiece;

    void DrawNextPiece(const Piece &piece) const;

    void HandleInput();
    void ApplyGravity();
    void LockAndSpawn();

    bool TryMove(int dRow, int dCol);
    bool TryRotate();
};