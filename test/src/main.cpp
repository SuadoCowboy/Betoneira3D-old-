#include "engine.h"

#include <iostream>
#include <string>

int main(int, char**)
{
    Betoneira::init();

    Betoneira::Window window(800, 600, "Betoneira3D Dev's Little Sandbox");

    Betoneira::Color backgroundColor(21, 30, 59);

    Betoneira::Shader simpleShader;

    {
        Betoneira::FileSystem::FileHandler fileHandler{"assets/shaders/simple2D.vert"};
        fileHandler.open(Betoneira::FileSystem::FILE_READ);

        std::string vertexShaderSource = fileHandler.read();
        
        fileHandler.open("assets/shaders/simple2D.frag", Betoneira::FileSystem::FILE_READ);
        std::string fragmentShaderSource = fileHandler.read();
        fileHandler.close();
        
        simpleShader.compile(vertexShaderSource.c_str(), fragmentShaderSource.c_str());
    }

    Betoneira::Graphics2D::Triangle triangle{simpleShader, {0.5f, -0.5f}, {-0.5f, -0.5f}, {0.0f, 0.5f} };

    while (!window.shouldClose())
    {
        window.fill(backgroundColor);

        Betoneira::Input::update();

        triangle.setGLColor(.0f, sin(Betoneira::Time::getTime()) / 2.0f + 0.5f, .0f, 1.0f);
        triangle.draw(window);

        if (Betoneira::Input::keyJustPressed(Betoneira::Input::Keys::Q))
            backgroundColor.setColor(Betoneira::Random::randomColor());
        
        window.clear();
    }

    Betoneira::quit();
    return EXIT_SUCCESS;
}