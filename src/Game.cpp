#include "../include/Game.h"
#include "../include/Board.h"
#include <iostream>

using namespace std;

Game::Game(int width, int height)
{
    screenWidth = width;
    screenHeight = height;
    Init();
}

Game::~Game()
{
    CloseWindow();
}

void Game::Init()
{
    InitWindow(screenWidth, screenHeight, "Tetriz");
    SetTargetFPS(60);

    currentPiece = Piece{static_cast<PieceType>(GetRandomValue(0, 6))};
    nextPiece = Piece{static_cast<PieceType>(GetRandomValue(0, 6))};

    if (!IsWindowReady())
        cout << "Failed to initialize window!" << endl;
}

void Game::Update()
{
    if (gameOver)
        return;

    if (IsKeyPressed(KEY_LEFT))
    {
        currentPiece.MoveLeft();
        if (!board.IsValid(currentPiece))
            currentPiece.MoveRight();
    }
    if (IsKeyPressed(KEY_RIGHT))
    {
        currentPiece.MoveRight();
        if (!board.IsValid(currentPiece))
            currentPiece.MoveLeft();
    }

    if (IsKeyDown(KEY_DOWN))
    {
        currentPiece.MoveDown();
        if (!board.IsValid(currentPiece))
            currentPiece.MoveUp();
    }

    if (IsKeyPressed(KEY_Q))
    {
        currentPiece.Rotate();
        if (!board.IsValid(currentPiece))
            currentPiece.UndoRotate();
    }

    fallTimer += GetFrameTime();

    if (fallTimer >= fallDelay)
    {
        currentPiece.MoveDown();

        if (!board.IsValid(currentPiece))
        {
            currentPiece.MoveUp();
            board.LockPiece(currentPiece);

            int linesCleared = board.ClearFullRows();
            score += linesCleared;

            currentPiece = nextPiece;
            nextPiece = Piece{static_cast<PieceType>(GetRandomValue(0, 6))};
        }

        fallTimer = 0.0f;
    }

    if (board.IsFull())
        gameOver = true;
}

void Game::DrawNextPiece(const Piece &piece) const
{
    int startX = BOARD_WIDTH + 50;
    int startY = 230;

    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (piece.getShape()[r][c] != 0)
            {
                int posX = startX + c * CELL_SIZE;
                int posY = startY + r * CELL_SIZE;

                DrawRectangle(posX, posY, CELL_SIZE, CELL_SIZE, SKYBLUE);
                DrawRectangleLines(posX, posY, CELL_SIZE, CELL_SIZE, DARKGRAY);
            }
        }
    }
}

void Game::DrawSidePanel() const
{
    int x = BOARD_WIDTH;

    DrawRectangle(x, 0, SIDE_PANEL_WIDTH, SCREEN_HEIGHT, DARKGRAY);
    DrawText("TETRIZ", x + 20, 20, 40, WHITE);
    DrawText(TextFormat("Score: %d", score), x + 20, 100, 30, WHITE);
    DrawText("Next:", x + 20, 180, 30, WHITE);

    DrawNextPiece(nextPiece);
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    board.Draw();

    if (!gameOver)
        currentPiece.Draw();
    else
        DrawText("GAME OVER", 80, 450, 60, RED);

    DrawSidePanel();

    EndDrawing();
}

void Game::Run()
{
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
}