#include "window.h"

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