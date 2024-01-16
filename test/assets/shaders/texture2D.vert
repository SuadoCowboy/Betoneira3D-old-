#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTextureCoordinates;

out vec2 textureCoordinates;

uniform mat4 transform;

void main()
{
    textureCoordinates = aTextureCoordinates;
    gl_Position = transform * vec4(aPos, 1.0f);
}