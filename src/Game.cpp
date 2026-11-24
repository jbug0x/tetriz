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

    if (!IsWindowReady())
        cout << "Failed to initialize window!" << endl;
}

void Game::Update()
{
    // Update game logic here
}

void Game::DrawSidePanel()
{
    int x = BOARD_WIDTH;

    DrawRectangle(x, 0, SIDE_PANEL_WIDTH, SCREEN_HEIGHT, DARKGRAY);
    DrawText("TETRIZ", x + 20, 20, 40, WHITE);
    DrawText(TextFormat("Score: %d", score), x + 20, 100, 30, WHITE);
    DrawText("Next:", x + 20, 180, 30, WHITE);
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    board.Draw();
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