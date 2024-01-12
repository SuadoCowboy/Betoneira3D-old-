#include "engine.h"

namespace bt = Betoneira;

int main(int, char**)
{
    bt::init();

    bt::Window::init(800, 600, "Betoneira3D Dev's Little Sandbox");

    bt::Color backgroundColor(21, 30, 59);

    bt::Shader simpleShader;
    {
        Betoneira::FileSystem::FileHandler fileHandler{"assets/shaders/simple2D.vert"};
        fileHandler.open(Betoneira::FileSystem::FILE_READ);

        std::string vertexShaderSource = fileHandler.read();
        
        fileHandler.open("assets/shaders/simple2D.frag", Betoneira::FileSystem::FILE_READ);
        std::string fragmentShaderSource = fileHandler.read();
        fileHandler.close();
        
        simpleShader.compile(vertexShaderSource.c_str(), fragmentShaderSource.c_str());
    }

    float vertices[] = {
        // positions
         0.5f,  0.5f, 0.0f, // top right
         0.5f, -0.5f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, // top left
    };
    
    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    bt::Graphics::Mesh2D square{simpleShader, vertices, indices};

    while (!bt::Window::shouldClose())
    {
        bt::Window::fill(backgroundColor);

        square.draw();
        
        bt::Window::clear();
    }

    bt::quit();
    return EXIT_SUCCESS;
}