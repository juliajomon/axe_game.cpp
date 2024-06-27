// axe_game.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "raylib.h"
#include <iostream>

int main()
{
    //dimensions
    int width = 800;
    int length = 450;

    //dimension for circle
    int x = width / 2;
    int y = length / 2;
    float rad = 15.5f;
    int axe_x = 300;
    int axe_y = 0;

    //setting boundary
    int left_circle = x - rad,
        right_circle = x + rad,
        up_circle = y - rad,
        down_circle = y + rad;

    int left_rect = axe_x,
        right_rect = axe_x + 50,
        up_rect = axe_y,
        down_rect = axe_y + 50;

    bool Detect_collision = (left_rect <= right_circle) &&
                            (right_rect >= left_circle) &&
                            (up_rect <= down_circle) &&
                            (down_rect >= up_circle);
    //window screen
    InitWindow(width, length, "Julia");

    SetTargetFPS(60);

    while (WindowShouldClose() == false) {

        if (IsKeyPressed(KEY_F11))                  // Detect F11 to Enter Full-Screen
        {
            ToggleFullscreen();
        } 

        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(x, y, rad, BLUE);
        DrawRectangle(axe_x, axe_y, 50, 50, RED);
       

        if (Detect_collision == true) {
            DrawText("GAME OVER", width / 2, length / 2, 20, BLACK);
        }
        else {
            left_circle = x - rad;
            right_circle = x + rad;
            up_circle = y - rad;
            down_circle = y + rad;

            left_rect = axe_x;
            right_rect = axe_x + 50;
            up_rect = axe_y;
            down_rect = axe_y + 50;

            //movement of circle and keeping within boundary
            if (IsKeyDown(KEY_D) && x + rad < width) {
                x = x + 10;
            }
            else if (IsKeyDown(KEY_A) && x - rad > 0) {
                x = x - 10;
            }
            else if (IsKeyDown(KEY_S) && y + rad < length) {
                y = y + 10;
            }
            else if (IsKeyDown(KEY_W) && y - rad > 0) {
                y = y - 10;
            }

            if (IsKeyDown(KEY_UP) && x > 0) {
                axe_y = axe_y - 10;
             
            }
            if (IsKeyPressed(KEY_DOWN) && y < length) {
                axe_y = axe_y + 10;
                
            }
            if (IsKeyDown(KEY_RIGHT && x < width)) {
                axe_x += 10;
                
            }
            if (IsKeyPressed(KEY_LEFT) && y > 0) {
                axe_x -= 10;
                
            }
        }
        
        
        EndDrawing();
    }


}


