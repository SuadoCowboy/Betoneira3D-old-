#pragma once

// see https://www.glfw.org/docs/3.3/input_guide.html to update this class

#include "shared/shared.h"
#include "window/window.h"
#include <map>

namespace Betoneira
{
    namespace Input
    {
        enum Keys
        {
            // because we're just testing, there's no reason to store every key at the moment
            Q = GLFW_KEY_Q,
            W = GLFW_KEY_W,
            A = GLFW_KEY_A,
            S = GLFW_KEY_S,
            D = GLFW_KEY_D
        };

        
        /*enum MouseKeys
        {
            MOUSE1 = GLFW_MOUSE_BUTTON_LEFT,
            MOUSE2 = GLFW_MOUSE_BUTTON_RIGHT,
            MOUSE3 = GLFW_MOUSE_BUTTON_MIDDLE,
            MOUSE4 = GLFW_MOUSE_BUTTON_4,
            MOUSE5 = GLFW_MOUSE_BUTTON_5,
            MOUSE6 = GLFW_MOUSE_BUTTON_6,
            MOUSE7 = GLFW_MOUSE_BUTTON_7,
            MOUSE8 = GLFW_MOUSE_BUTTON_8
        };
        */
        
        extern std::map<int, bool> keysPressed;
        extern std::map<int, bool> keysJustPressed;
        extern std::map<int, bool> keysJustReleased;

        void update();
        bool keyPressed(int key);
        bool keyJustPressed(int key);
        bool keyJustReleased(int key);
    }

    /*namespace Input
    {
        void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);

        std::map<int, bool> keys = {{GLFW_KEY_A, false}, {GLFW_KEY_A, false}, {GLFW_KEY_S, false}, {GLFW_KEY_D, false}};
        std::map<int, bool> modifiers = {{GLFW_MOD_ALT, false}, {GLFW_MOD_CAPS_LOCK, false}, {GLFW_MOD_CONTROL, false}, {GLFW_MOD_NUM_LOCK, false}, {GLFW_MOD_SHIFT, false}, {GLFW_MOD_SUPER, false}};
    }*/
}