#include "window.h"

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
    
    //glfwSetKeyCallback(glfwWindow, Input::KeyCallBack); // I believe this call back is more useful for texting than actual in-game key input
    Input::GLFWWindow = glfwWindow;
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

void Window::fill(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    glClearColor(Color::byteToGLfloat(r), Color::byteToGLfloat(g), Color::byteToGLfloat(b), Color::byteToGLfloat(a));
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::fill(Color color)
{
    fill(color.getR(), color.getG(), color.getB(), color.getA());
}

void Window::clear()
{
    glfwSwapBuffers(glfwWindow);
    glfwPollEvents();
}