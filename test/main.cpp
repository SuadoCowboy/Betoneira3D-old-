#include <iostream>

#include "engine.h"

int main(int, char**)
{
    Betoneira::init();

    Betoneira::Color backgroundColor(51, 127, 76);

    Betoneira::Window window(800, 600, "2D Game Test");
    while (!window.shouldClose())
    {
        window.fill(backgroundColor);

        window.clear();
    }

    Betoneira::quit();
    return EXIT_SUCCESS;
}