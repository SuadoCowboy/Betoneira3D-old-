#include "mesh2dTextured.h"

using namespace Betoneira;
using namespace Graphics;

Mesh2DTextured::~Mesh2DTextured(){}

Texture& Mesh2DTextured::getTexture()
{
    return texture;
}

void Mesh2DTextured::draw()
{
    texture.bind();
    Mesh2D::draw();
}