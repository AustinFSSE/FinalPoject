#pragma once
#pragma once
#include <raylib.h>

class Laser {
private:
    
    Vector2 position;
    bool active;

public:
    Laser();
    void Update();
    void Draw();
    void Fire(Vector2 startPosition);
    bool IsActive() const;
    Vector2 GetPosition();
    float GetWidth();
    float GetHeight();
};
