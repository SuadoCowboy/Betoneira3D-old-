#include "input/input.h"

using namespace Betoneira;

std::map<int, bool> Input::keysPressed {{Input::Q, false}, {Input::W, false}, {Input::A, false}, {Input::S, false}, {Input::D, false}};
std::map<int, bool> Input::keysJustPressed {{Input::Q, false}, {Input::W, false}, {Input::A, false}, {Input::S, false}, {Input::D, false}};
std::map<int, bool> Input::keysJustReleased {{Input::Q, false}, {Input::W, false}, {Input::A, false}, {Input::S, false}, {Input::D, false}};

GLFWwindow* Input::GLFWWindow = nullptr; // this value will be set by the last loaded Window class

bool Input::keyPressed(int key)
{
    return (glfwGetKey(GLFWWindow, key) == GLFW_PRESS);
}

void Input::update()
{
    for (auto pair : keysPressed)
    {
        if (keyPressed(pair.first))
        {
            if (keysPressed[pair.first] == false)
                keysJustPressed[pair.first] = true;
            else
                keysJustPressed[pair.first] = false;
            
            keysPressed[pair.first] = true;
        }
        else
        {
            if (keysJustReleased[pair.first] == false && keysPressed[pair.first] == true)
                keysJustReleased[pair.first] = true;
            else
                keysJustReleased[pair.first] = false;

            keysPressed[pair.first] = false;
        }
    }
}

bool Input::keyJustPressed(int key)
{
    return keysJustPressed[key];
}

bool Input::keyJustReleased(int key)
{
    return keysJustReleased[key];
}

// FOR TEXT INPUT, LOOK: https://www.glfw.org/docs/3.3/input_guide.html#input_char
/*void Input::KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{ // This code wasn't tested!!!
    for (auto pair : Input::keys)
    {
        if (key == pair.first)
        {
            if (action == GLFW_PRESS)
                Input::keys[key] = true;
            else if (action == GLFW_RELEASE)
                Input::keys[key] = false;
        }
    }

    for (auto pair: Input::modifiers)
    {
        if (mods & pair.first)
            Input::modifiers[pair.first] = true;
        else
            Input::modifiers[pair.first] = false;
    }
}*/