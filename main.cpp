#include <iostream>
#include <raylib.h>
#include "game.h"
#include "colors.h"

using namespace std;

// JEDYNY PROBLEM Z GRĄ TO BRAK WYŚWIETLAJĄCEJ SIĘ PUNKTACJI, IDK WHY BRO

double lastUpdateTime = 0;

bool EventTriggerd(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main () 
{
    InitWindow(500, 620, "Projekt z poradnikiem z YT: Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("font/Debrosee-ALPnL.ttf", 64, 0, 0);

    Game game = Game();

    while(WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if(EventTriggerd(0.3))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {350, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {360, 175}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {324, 450}, 32, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}