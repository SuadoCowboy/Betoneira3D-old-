#include <iostream>

#include "engine.h"

int main(int, char**)
{
    Betoneira::init();

    Betoneira::Window window(800, 600, "2D Game Test");
    while (!window.shouldClose())
    {
        window.fill(0.2f, 0.5f, 0.3f);

        window.clear();
    }

    Betoneira::quit();
    return EXIT_SUCCESS;
}