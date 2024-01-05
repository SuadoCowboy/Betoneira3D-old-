#include "window.h"

#include "shared/shared.h"

#include <iostream>

using namespace Betoneira;

Window::Window(int width, int height, std::string title)
{
    glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (glfwWindow == NULL)
    {
        std::cerr << "ERROR::ENGINE: Failed to create GLFW window." << std::endl;
        quit();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(glfwWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        quit();
        exit(EXIT_FAILURE);
    }
}

Window::~Window(){}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(glfwWindow);
}

void Window::close()
{
    glfwSetWindowShouldClose(glfwWindow, true);
}

void Window::fill(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::fill(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::clear()
{
    glfwSwapBuffers(glfwWindow);
    glfwPollEvents();
}