#include "engine.h"

#include <iostream>

namespace bt = Betoneira;

int main(int, char**)
{
    bt::init();
    bt::Window::init(800, 600, "Betoneira3D Dev's Little Sandbox");

    bt::Color backgroundColor(21, 30, 59);

    bt::Shader textureShader{"assets/shaders/texture2D.vert", "assets/shaders/texture2D.frag"};

    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };
    
    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    bt::Graphics::TextureMesh2D rectangle{textureShader, vertices, indices, "assets/textures/betoneira cromada.jpg"};
    
    rectangle.addAttribute(0, 3, 8, 0); // position
    rectangle.addAttribute(1, 3, 8, 3); // color
    rectangle.addAttribute(2, 2, 8, 6); // texture position

    while (!bt::Window::shouldClose())
    {
        bt::Window::fill(backgroundColor);

        rectangle.draw();
        
        bt::Window::clear();
    }

    bt::quit();
    return EXIT_SUCCESS;
}