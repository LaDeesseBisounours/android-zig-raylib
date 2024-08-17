#include "raylib.h"
#include <android/log.h>

int main() {
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    InitWindow(width, height, "BonjourMonde");

    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    SetTargetFPS(30);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Hello", 100, 100, 70, BLACK);
        EndDrawing();
    }

    return 0;
}
