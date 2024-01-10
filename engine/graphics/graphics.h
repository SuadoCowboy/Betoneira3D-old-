#pragma once

#include "shared/shared.h"
#include "shader/shader.h"
#include "vector/vector.h"
#include "window/window.h"

namespace Betoneira::Graphics2D
{
    class Triangle
    {
    public:
        Triangle(Shader& shader, const Vector2f& point1, const Vector2f& point2, const Vector2f& point3);
        ~Triangle();

        void draw(Window& window);
    private:
        Shader* shader;
        unsigned int VBO, VAO;
    };
}

/*namespace Betoneira::Graphics3D
{
    class Box
    {
    public:
        // might need to check if opengl renders using unsigned or signed int
        Box(int x, int y, int z, unsigned int width, unsigned int height, unsigned int depth);
        ~Box();
    }
}
*/