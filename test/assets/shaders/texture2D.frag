#version 330 core
out vec4 fragColor;

in vec2 textureCoordinates;
in vec3 ourColor;

uniform sampler2D textureSampler;

void main()
{    
    fragColor = texture(textureSampler, textureCoordinates) * ourColor;
}