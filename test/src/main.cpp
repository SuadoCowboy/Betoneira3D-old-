#include "engine.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

namespace bt = Betoneira;

int main(int, char**)
{
    bt::init();
    bt::Window::init(800, 600, "Betoneira3D Dev's Little Sandbox");

    bt::Color backgroundColor(21, 30, 59);

    bt::Shader textureShader{"assets/shaders/texture2D.vert", "assets/shaders/texture2D.frag"};

    float vertices[] = {
        // positions          // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f    // top left 
    };
    
    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    //simpleShader.setVector4f("color", 0.9764f, 0.8078f, 0.9254f, 1.0f, true);

    bt::Graphics::TextureMesh2D rectangle{textureShader, vertices, indices, "assets/textures/betoneira cromada.jpg"};

    rectangle.addAttribute(0, 3, 5, 0); // position
    rectangle.addAttribute(1, 2, 5, 3); // texture position

    while (!bt::Window::shouldClose())
    {
        bt::Window::fill(backgroundColor);


        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

        textureShader.setMatrix4x4("transform", transform, true);

        rectangle.draw();
        
        bt::Window::clear();
    }

    bt::quit();
    return EXIT_SUCCESS;
}