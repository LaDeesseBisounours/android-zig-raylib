const raylib = @cImport({
    @cInclude("raylib.h");
});

const std = @import("std");
const testing = std.testing;

//A very complex function that really required to be exported as a library

export fn runApp() c_int {
    const width = raylib.GetScreenWidth();
    const height = raylib.GetScreenHeight();

    raylib.InitWindow(width, height, "BonjourMonde");

    raylib.SetConfigFlags(raylib.FLAG_FULLSCREEN_MODE);
    raylib.SetTargetFPS(30);

    while (!raylib.WindowShouldClose()) {
        raylib.BeginDrawing();
        raylib.ClearBackground(raylib.WHITE);
        raylib.DrawText("Hello from Zig", 100, 100, 70, raylib.BLACK);
        raylib.EndDrawing();
    }

    return 0;
}
