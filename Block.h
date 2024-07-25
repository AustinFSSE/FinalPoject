#pragma once
#include <raylib.h>

class Block {

public:
	Block(Vector2 position, float speed);

	void Update();
	void Draw();
private:
	Vector2 position;
	float speed = 10.0;
};