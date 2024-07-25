#include "Game.h"

Game::Game() : state(GameState::MENU) {}

void Game::LoadTextures()
{
    spaceship.LoadSpaceshipTexture();
    // Load textures for aliens, etc.
}

void Game::Update()
{
    switch (state)
    {
    case GameState::MENU:
        UpdateMenu();
        break;
    case GameState::PLAYING:
        UpdatePlaying();
        break;
    case GameState::EXIT:
        // Clean up if needed
        break;
    }
}

void Game::Draw()
{
    switch (state)
    {
    case GameState::MENU:
        DrawMenu();
        break;
    case GameState::PLAYING:
        DrawPlaying();
        break;
    case GameState::EXIT:
        // Maybe draw a closing screen or nothing
        break;
    }
}

void Game::Unload()
{
    spaceship.Unload();
    // Unload other textures
}

void Game::DrawMenu()
{
    ClearBackground(DARKGRAY);
    DrawText("Space Rocks", GetScreenWidth() / 2 - MeasureText("Space Rocks", 40) / 2, GetScreenHeight() / 2 - 40, 40, WHITE);
    DrawText("Press ENTER to Start", GetScreenWidth() / 2 - MeasureText("Press ENTER to Start", 20) / 2, GetScreenHeight() / 2 + 20, 20, WHITE);
    DrawText("Press ESC to Exit", GetScreenWidth() / 2 - MeasureText("Press ESC to Exit", 20) / 2, GetScreenHeight() / 2 + 60, 20, WHITE);
}

void Game::UpdateMenu()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        state = GameState::PLAYING;
    }
    if (IsKeyPressed(KEY_ESCAPE))
    {
        state = GameState::EXIT;
    }
}

void Game::DrawPlaying()
{
    ClearBackground(DARKGRAY);
    spaceship.Draw();
    for (auto& laser : lasers) {
        laser.Draw();
    }
    for (auto& alien : aliens) {
        alien.Draw();
    }
    for (auto& alien2 : aliens2) {
        alien2.Draw();
    }
}

void Game::UpdatePlaying()
{
    spaceship.Update();

    double currentTime = GetTime();
    if (currentTime - spawnTimer >= spawnInterval)
    {
        Alien newAlien;
        newAlien.LoadAlienTexture();
        aliens.push_back(newAlien);

        Alien2 newAlien2;
        newAlien2.LoadAlien2Texture();
        aliens2.push_back(newAlien2);

        spawnTimer = currentTime;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 laserPosition = {
            spaceship.GetPosition().x + spaceship.GetWidth() / 2 - 2,
            spaceship.GetPosition().y - 20
        };
        Laser newLaser;
        newLaser.Fire(laserPosition);
        lasers.push_back(newLaser);
    }

    UpdateLasers();

    HandleCollisions();

    for (auto& alien : aliens) {
        alien.Update();
    }
    for (auto& alien2 : aliens2) {
        alien2.Update();
    }
}

void Game::UpdateLasers()
{
    for (auto& laser : lasers) {
        laser.Update();
    }
}


void Game::HandleCollisions()
{
    for (auto& laser : lasers) {
        if (laser.IsActive()) {
            Vector2 laserPos = laser.GetPosition();
            for (auto& alien : aliens) {
                Vector2 alienPos = alien.GetPosition();
                if (laserPos.x < alienPos.x + alien.GetWidth() &&
                    laserPos.x + laser.GetWidth() > alienPos.x &&
                    laserPos.y < alienPos.y + alien.GetHeight() &&
                    laserPos.y + laser.GetHeight() > alienPos.y) {
                    laser = Laser(); // Deactivate laser
                    alien = Alien(); // Deactivate alien (or remove from vector)
                    break;
                }
            }
            for (auto& alien2 : aliens2) {
                Vector2 alien2Pos = alien2.GetPosition();
                if (laserPos.x < alien2Pos.x + alien2.GetWidth() &&
                    laserPos.x + laser.GetWidth() > alien2Pos.x &&
                    laserPos.y < alien2Pos.y + alien2.GetHeight() &&
                    laserPos.y + laser.GetHeight() > alien2Pos.y) {
                    laser = Laser(); // Deactivate laser
                    alien2 = Alien2(); // Deactivate alien2 (or remove from vector)
                    break;
                }
            }
        }
    }
}
