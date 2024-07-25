#pragma once
#include <raylib.h>

class Button {

public:
	Button(Rectangle bounds, const char* text);
	void Draw();
	bool isClicked() const;

private:
	Rectangle bounds;
	const char* text;
	Color GetBackgroundColor() const;
};