#include "Alien2.h"

void Alien2::LoadAlien2Texture()
{
    Image image = LoadImage("Graphics/alien_2.png");
    texture = LoadTextureFromImage(image);
    position = { (float)(GetRandomValue(150, 275)), (float)(GetRandomValue(250, 375)) };
    direction = 1;
}

void Alien2::Update()
{
    position.x += direction * 5.0f;
    if (position.x <= 0 || position.x > GetScreenWidth() - texture.width) {
        direction *= -1;
    }
}

void Alien2::Draw()
{
    DrawTexture(texture, (int)(position.x), (int)(position.y), WHITE);
}

void Alien2::Unload()
{
    UnloadTexture(texture);
}

Vector2 Alien2::GetPosition()
{
    return position;
}

float Alien2::GetWidth()
{
    return (float)texture.width;
}

float Alien2::GetHeight()
{
    return (float)texture.height;
}
