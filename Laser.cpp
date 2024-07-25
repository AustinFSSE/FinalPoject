#include "Laser.h"

Laser::Laser() : active(false) {}

void Laser::Update()
{
    if (active) {
        position.y -= 10.0f; // Move the laser upwards
        if (position.y < -10) { // Check if laser is off-screen
            active = false;
        }
    }
}

void Laser::Draw()
{
    if (active) {
        DrawRectangle((int)position.x, (int)position.y, 5, 20, RED); // Draw a red rectangle as laser
    }
}

void Laser::Fire(Vector2 startPosition)
{
    position = startPosition;
    active = true;
}

bool Laser::IsActive() const
{
    return active;
}

Vector2 Laser::GetPosition()
{
    return position;
}

float Laser::GetWidth()
{
    return 5.0f;
}

float Laser::GetHeight()
{
    return 20.0f;
}


