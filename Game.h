#pragma once
#include <raylib.h>
#include "Alien.h"
#include "Alien2.h"
#include "Spaceship.h"
#include "Laser.h"
#include "GameState.h"
#include <vector>

class Game
{
private:
    GameState state;
    Spaceship spaceship;
    std::vector<Alien> aliens;
    std::vector<Alien2> aliens2;
    std::vector<Laser> lasers;

    double spawnTimer;
    const double spawnInterval = 2.0;

    void DrawMenu();
    void UpdateMenu();
    void DrawPlaying();
    void UpdatePlaying();
    void UpdateLasers();
    void HandleCollisions();

public:
    Game();
    void LoadTextures();
    void Update();
    void Draw();
    void Unload();
};

