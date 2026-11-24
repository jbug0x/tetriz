#include "Game.h"
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
    WindowShouldClose(); // Close window and OpenGL context
}

void Game::Init()
{
    InitWindow(this->screenWidth, this->screenHeight, "Tetriz");
    SetTargetFPS(60);

    if (!IsWindowReady())
    {
        cout << "Failed to initialize window!" << endl;
    }

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }   
}

void Game::Update()
{
    // Update game logic here
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw game elements here

    EndDrawing();
}