#version 330 core

out vec4 FragColor;

in vec4 ourPos;

void main()
{
    FragColor = vec4(ourPos.x+0.9764f, ourPos.y+0.8078f, ourPos.z+0.9254f, 1.0f);
}