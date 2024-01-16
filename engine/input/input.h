#pragma once

// see https://www.glfw.org/docs/3.3/input_guide.html to update this class

#include <string>
#include <map>

namespace Betoneira::Input
{
    extern std::map<std::string, int> keys;
    //extern std::map<std::string, unsigned int> mouseKeys;

    extern std::map<int, bool> keysPressed;
    extern std::map<int, bool> keysJustPressed;
    extern std::map<int, bool> keysJustReleased;

    void init();
    void update();
    bool keyPressed(int key);
    bool keyJustPressed(int key);
    bool keyJustReleased(int key);
}