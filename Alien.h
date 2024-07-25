#pragma once
#include <raylib.h>

class Alien
{
private:
    Texture2D texture;
    Vector2 position;
    int direction;

public:
    void LoadAlienTexture();
    void Update();
    void Draw();
    void Unload();
    Vector2 GetPosition() const;
    float GetWidth() const;
    float GetHeight() const;
};
