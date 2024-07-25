#include <raylib.h>
#include "Game.h"

const int screenWidth = 800;
const int screenHeight = 600;

int main() {
    InitWindow(screenWidth, screenHeight, "Space Rocks");

    Game game;
    game.LoadTextures();

    SetTargetFPS(60);  // Set FPS to 60

    while (!WindowShouldClose()) {  // Main game loop
        game.Update();
        BeginDrawing();
        ClearBackground(DARKGRAY);
        game.Draw();
        EndDrawing();
    }

    game.Unload();
    CloseWindow();

    return 0;
}
