#pragma once
#include <raylib.h>

class Alien2
{
private:
    Texture2D texture;
    Vector2 position;
    int direction;

public:
    void LoadAlien2Texture();
    void Update();
    void Draw();
    void Unload();
    Vector2 GetPosition();
    float GetWidth();
    float GetHeight();
};
