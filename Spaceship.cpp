#include "Spaceship.h"

void Spaceship::LoadSpaceshipTexture()
{
	Image image = LoadImage("Graphics/spaceship.png");
	texture = LoadTextureFromImage(image);
	position = { (float)(GetScreenWidth() / 2), (float)(GetScreenHeight() - texture.height) };
}

void Spaceship::Update()
{
	if (IsKeyDown(KEY_D))
	{
		if (position.x >= GetScreenWidth() - texture.width)
		{
			position.x = GetScreenWidth() - texture.width - 10;
		}
		position.x += 10.0f;
	}
	if (IsKeyDown(KEY_A)) 
	{
		if (position.x <= 0)
		{
			position.x = 10;
		}
		position.x -= 10.0f;
	}
}

void Spaceship::Draw()
{
	
	DrawTexture(texture, (int)(position.x), (int)(position.y), WHITE);
}
void Spaceship::Unload()
{
	UnloadTexture(texture);
}

Vector2 Spaceship::GetPosition()
{
	return position;
}

float Spaceship::GetWidth()
{
	return (float)texture.width;
}

float Spaceship::GetHeight()
{
	return (float)texture.height;
}

