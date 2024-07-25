#include "Alien.h"

void Alien::LoadAlienTexture()
{
    Image image = LoadImage("Graphics/alien_1.png");
    texture = LoadTextureFromImage(image);
    position = { (float)(GetRandomValue(25, 150)) , (float)(GetRandomValue(25, 250)) };
    direction = 1;
}

void Alien::Update()
{
    position.x += direction * 5.0f;
    if (position.x <= 0 || position.x > GetScreenWidth() - texture.width) {
        direction *= -1;
    }
}

void Alien::Draw()
{
    DrawTexture(texture, (int)(position.x), (int)(position.y), WHITE);
}

void Alien::Unload()
{
    UnloadTexture(texture);
}

Vector2 Alien::GetPosition() const
{
    return position;
}

float Alien::GetWidth() const
{
    return (float)texture.width;
}

float Alien::GetHeight() const
{
    return (float)texture.height;
}
