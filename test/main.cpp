#include <iostream>

#include "engine.h"

int main(int, char**)
{
    Betoneira::init();

    Betoneira::Color backgroundColor(255,255,0);//Betoneira::Random::randomColor());

    Betoneira::Window window(800, 600, "2D Game Test");
    while (!window.shouldClose())
    {
        window.fill(backgroundColor);

        Betoneira::Input::update();

        if (Betoneira::Input::keyJustPressed(Betoneira::Input::Keys::Q))
            backgroundColor.setColor(Betoneira::Random::randomColor());
        
        window.clear();
    }

    Betoneira::quit();
    return EXIT_SUCCESS;
}