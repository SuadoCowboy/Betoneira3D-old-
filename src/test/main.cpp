#include <iostream>

#include "engine.h"

class Game
{
public:
    Game(){}
    ~Game(){}

    void run()
    {
        Betoneira::Window window{500, 500, "Test game 2D"};

        while (!window.shouldClose())
        {
            window.fill(0.2f, 0.3f, 0.3f);
            
            window.clear();
        }
    }
};

int main(int, char**)
{
    Betoneira::init();

    Game game{};
    game.run();

    Betoneira::quit(EXIT_SUCCESS); // already exits the process
}