#include "raylib.h"

int main()
{
    int width = 800;
    int height = 400;
    int width_half = width/2;
    int height_half = height/2;
    int centerX = width_half - 100;
    int centerY = height_half;
    int radius = 25;
    int maxX = width - radius;
    int minX = radius;
    int axeLength = 50;
    int axeX = width_half + axeLength;
    int axeY = 0;
    int direction = 10;
    int l_circle_X = centerX - radius;
    int r_circle_X = centerX + radius;
    int u_circle_Y = centerY - radius;
    int b_circle_Y = centerY + radius;
    int l_axe_X = axeX;
    int r_axe_X = axeX + axeLength;
    int u_axe_Y = axeY;
    int b_axe_Y = axeY + axeLength;
    bool collision_with_axe = 
                                ((b_axe_Y >= u_circle_Y) && 
                                (u_axe_Y <= b_circle_Y) && 
                                (r_axe_X >= l_circle_X) && 
                                (l_axe_X <= r_circle_X));

    InitWindow(width, height, "Faiaz");

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            DrawText("Game Over!", width_half, height_half, 40, RED);
        }

        else
        {
                l_circle_X = centerX - radius;
                r_circle_X = centerX + radius;
                u_circle_Y = centerY - radius;
                b_circle_Y = centerY + radius;
                l_axe_X = axeX;
                r_axe_X = axeX + axeLength;
                u_axe_Y = axeY;
                b_axe_Y = axeY + axeLength;

                collision_with_axe = 
                                ((b_axe_Y >= u_circle_Y) && 
                                (u_axe_Y <= b_circle_Y) && 
                                (r_axe_X >= l_circle_X) && 
                                (l_axe_X <= r_circle_X));

            DrawCircle(centerX, centerY, radius, GREEN);
            DrawRectangle(axeX, axeY, axeLength, axeLength, PURPLE);

            axeY += direction;

            if (axeY > (height - axeLength) || axeY < 0)
            {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && centerX < maxX)
            {
                centerX += 10;
            }

            if (IsKeyDown(KEY_A) && centerX > minX)
            {
                centerX -= 10;
            }
        }

        EndDrawing();
    }
}