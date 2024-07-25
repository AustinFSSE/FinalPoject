#pragma once

#ifndef MENU_H
#define MENU_H

#include "Button.h"

enum class MenuState {
    MAIN,
    OPTIONS,
    EXIT
};

class Menu {
public:
    Menu();
    void Update();
    void Draw();
    MenuState GetCurrentState() const;

private:
    MenuState currentState;
    Button startButton;
    Button optionsButton;
    Button quitButton;

    void UpdateMainMenu();
    void UpdateOptionsMenu();
};

#endif // MENU_H
