#include "raylib.h"
#include <android/log.h>
#include <sstream>

extern "C" { int runApp(); }

int main() {
    return runApp();
//    int width = GetScreenWidth();
//    int height = GetScreenHeight();
//
//    InitWindow(width, height, "BonjourMonde");
//
//    SetConfigFlags(FLAG_FULLSCREEN_MODE);
//    SetTargetFPS(30);
//
//    std::stringstream ss;
//    int a = 7;
//    int b = 27;
//    ss << a << " + " << b << " = " << add(a, b) << std::endl;
//
//    while (!WindowShouldClose()) {
//        BeginDrawing();
//        ClearBackground(WHITE);
//        DrawText(ss.str().c_str(), 100, 100, 70, BLACK);
//        EndDrawing();
//    }
//
//    return 0;
}
