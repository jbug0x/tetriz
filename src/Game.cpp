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

bool Game::TryMove(int dRow, int dCol)
{
    Piece test = currentPiece;
    test.Move(dRow, dCol);
    if (!board.IsValid(test))
        return false;

    currentPiece = test;
    return true;
}

bool Game::TryRotate()
{
    Piece test = currentPiece;
    test.Rotate();
    if (!board.IsValid(test))
        return false;

    currentPiece = test;
    return true;
}

void Game::HandleInput()
{
    if (IsKeyPressed(KEY_LEFT))
        TryMove(0, -1);
    if (IsKeyPressed(KEY_RIGHT))
        TryMove(0, 1);
    if (IsKeyPressed(KEY_DOWN))
        TryMove(1, 0);
    if (IsKeyPressed(KEY_Q))
        TryRotate();
}

void Game::ApplyGravity()
{
    float delay = IsKeyDown(KEY_DOWN) ? softDropDelay : fallDelay;

    fallTimer += GetFrameTime();
    if (fallTimer >= delay)
    {
        fallTimer = 0.0f;

        if (!TryMove(1, 0))
            LockAndSpawn();
    }
}

void Game::LockAndSpawn()
{
    board.LockPiece(currentPiece);
    score += board.ClearFullRows();

    currentPiece = nextPiece;
    nextPiece = Piece{static_cast<PieceType>(GetRandomValue(0, 6))};

    if (!board.IsValid(currentPiece))
        gameOver = true;
}

void Game::Update()
{
    if (gameOver)
        return;

    HandleInput();
    ApplyGravity();
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