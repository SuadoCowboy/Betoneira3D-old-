#include "window.h"

using namespace Betoneira;

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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        quit();
        exit(EXIT_FAILURE);
    }
    
    //glfwSetKeyCallback(glfwWindow, Input::KeyCallBack); // I believe this call back is more useful for texting than actual in-game key input
    Input::GLFWWindow = glfwWindow;
}

Window::Window(int width, int height, const std::string& title)
{
    init(width, height, title);
}

Window::Window(const Math::Vector2i& size, const std::string& title)
{
    init(size.x, size.y, title);
}

Window::Window(const Math::Vector2u& size, const std::string& title)
{
    init(size.x, size.y, title);
}

Window::Window(const Math::Vector2f& size, const std::string& title)
{
    init(size.x, size.y, title);
}

Window::~Window()
{
    if (glfwWindow)
        glfwDestroyWindow(glfwWindow);
}

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
    glClearColor(Color::byteToFloat(r), Color::byteToFloat(g), Color::byteToFloat(b), Color::byteToFloat(a));
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