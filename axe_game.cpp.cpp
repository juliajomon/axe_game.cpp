// axe_game.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "raylib.h"
#include <iostream>

int main()
{
    //dimensions
    int width = 500;
    int length = 400;

    //dimension for circle
    int x = 250;
    int y = 200;
    float rad = 15.5f;

    //window screen
    InitWindow(width, length, "Julia");

    SetTargetFPS(60);

    while(WindowShouldClose()== false) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircle(x, y, rad, BLUE);
        EndDrawing();
         
        //movement of circle and keeping within boundary
        if (IsKeyDown(KEY_D) && x < width) {
            x = x + 10;
        }
        if (IsKeyDown(KEY_A) && x > 0 ) {
            x = x - 10;
        }
        if (IsKeyDown(KEY_S) && y < length ){
            y = y + 10;
        }
        if (IsKeyDown(KEY_W) && y > 0) {
            y = y - 10;
        }
        
    }
    
    
}


