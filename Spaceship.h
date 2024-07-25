#pragma once
#include <raylib.h>


class Spaceship {

private:
	Texture2D texture;
	Vector2 position;


public:

	void LoadSpaceshipTexture();
	void Update();
	void Draw();
	void Unload();
	Vector2 GetPosition();
	float GetWidth();
	float GetHeight();
};

