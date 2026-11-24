#pragma once
#include "raylib.h"

class Game
{
public:
    Game(int width, int height);
    ~Game();

    void Init();
    void Update();
    void Draw();

private:
    int screenWidth;
    int screenHeight;
};