#pragma once
#include "Board.h"
#include "raylib.h"

class Game
{
public:
    Game(int width, int height);
    ~Game();

    void Init();
    void Update();
    void Draw();
    void Run();
    void DrawSidePanel();

private:
    int screenWidth;
    int screenHeight;
    int score;

    Board board;
};