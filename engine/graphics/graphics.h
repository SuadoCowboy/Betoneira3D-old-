#pragma once

#include "shared/shared.h"
#include "shader/shader.h"
#include "math/vector/vector.h"
#include "window/window.h"
#include "color/color.h"

namespace Betoneira::Graphics2D
{
    class Triangle
    {
    public:
        Triangle(Shader& shader, const Math::Vector2f& point1, const Math::Vector2f& point2, const Math::Vector2f& point3);
        ~Triangle();

        void setColor(unsigned int r, unsigned int g, unsigned int b, unsigned int a=255U);
        void setColor(Color color);
        void setColor(Math::Vector4c vector);
        void setGLColor(float r, float g, float b, float a);
        
        Color& getColor();

        void draw(Window& window);
    
    private:
        Shader* shader;
        unsigned int VBO, VAO;

        Color color{};

        void updateShaderColor();
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