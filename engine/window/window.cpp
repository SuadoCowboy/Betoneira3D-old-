#include "window.h"

#include <iostream>

using namespace Betoneira;

GLFWwindow* Window::glfwWindow = nullptr;

void Window::init(int width, int height, const std::string& title)
{
    glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (glfwWindow == NULL)
    {
        std::cerr << "ERROR::ENGINE: Failed to create GLFW window." << std::endl;
        quit();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(glfwWindow);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "ERROR::ENGINE: Could not initalize GLAD" << std::endl;
        quit();
        exit(EXIT_FAILURE);
    }

    glEnable(GL_DEPTH_TEST);
    
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
}

void Window::setSize(int width, int height)
{
    glfwSetWindowSize(glfwWindow, width, height);
}

void Window::setSize(const Math::Vector2i& size)
{
    glfwSetWindowSize(glfwWindow, size.x, size.y);
}

void Window::setSize(const Math::Vector2u& size)
{
    glfwSetWindowSize(glfwWindow, size.x, size.y);
}

void Window::setSize(const Math::Vector2f& size)
{
    glfwSetWindowSize(glfwWindow, size.x, size.y);
}

Math::Vector2i Window::getSize()
{
    int width, height;
    glfwGetWindowSize(glfwWindow, &width, &height);
    return {width, height};
}

void Window::setTitle(const char* title)
{
    glfwSetWindowTitle(glfwWindow, title);
}

Window::~Window()
{
    if (glfwWindow)
    {
        glfwDestroyWindow(glfwWindow);
        glfwWindow = nullptr;
    }
}

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::fill(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    fill(Color::byteToFloat(r), Color::byteToFloat(g), Color::byteToFloat(b), Color::byteToFloat(a));
}

void Window::fill(Color color)
{
    Math::Vector4f GLColor = color.getGLColor();
    fill(GLColor.x, GLColor.y, GLColor.z, GLColor.w);
}

void Window::clear()
{
    glfwSwapBuffers(glfwWindow);
    glfwPollEvents();
}