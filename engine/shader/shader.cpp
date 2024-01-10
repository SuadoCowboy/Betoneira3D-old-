#include "shader/shader.h"

#include <iostream>

using namespace Betoneira;

Shader::Shader(){}

Shader& Shader::use()
{ 
    glUseProgram(ID); 
    return *this;
}

void Shader::compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource)
{
    unsigned int vertexShader, fragmentShader, geometryShader;

    // vertex Shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    checkCompileErrors(vertexShader, "VERTEX");

    // fragment Shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    checkCompileErrors(fragmentShader, "FRAGMENT");
    
    // if geometry shader source code is given, also compile geometry shader
    if (geometrySource != nullptr)
    {
        geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geometryShader, 1, &geometrySource, NULL);
        glCompileShader(geometryShader);
        checkCompileErrors(geometryShader, "GEOMETRY");
    }

    // shader program
    ID = glCreateProgram();
    
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    
    if (geometrySource != nullptr)
        glAttachShader(ID, geometryShader);
    
    glLinkProgram(ID);
    
    checkCompileErrors(ID, "PROGRAM");
    
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    if (geometrySource != nullptr)
        glDeleteShader(geometryShader);
}

void Shader::setFloat(const char *name, float value, bool useShader)
{
    if (useShader)
        use();
    glUniform1f(glGetUniformLocation(ID, name), value);
}
void Shader::setInteger(const char *name, int value, bool useShader)
{
    if (useShader)
        use();
    glUniform1i(glGetUniformLocation(ID, name), value);
}
void Shader::setVector2f(const char *name, float x, float y, bool useShader)
{
    if (useShader)
        use();
    glUniform2f(glGetUniformLocation(ID, name), x, y);
}
void Shader::setVector2f(const char *name, const glm::vec2 &value, bool useShader)
{
    if (useShader)
        use();
    glUniform2f(glGetUniformLocation(ID, name), value.x, value.y);
}
void Shader::setVector3f(const char *name, float x, float y, float z, bool useShader)
{
    if (useShader)
        use();
    glUniform3f(glGetUniformLocation(ID, name), x, y, z);
}
void Shader::setVector3f(const char *name, const glm::vec3 &value, bool useShader)
{
    if (useShader)
        use();
    glUniform3f(glGetUniformLocation(ID, name), value.x, value.y, value.z);
}
void Shader::setVector4f(const char *name, float x, float y, float z, float w, bool useShader)
{
    if (useShader)
        use();
    glUniform4f(glGetUniformLocation(ID, name), x, y, z, w);
}
void Shader::setVector4f(const char *name, const glm::vec4 &value, bool useShader)
{
    if (useShader)
        use();
    glUniform4f(glGetUniformLocation(ID, name), value.x, value.y, value.z, value.w);
}
void Shader::setMatrix4(const char *name, const glm::mat4 &matrix, bool useShader)
{
    if (useShader)
        use();
    glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, false, glm::value_ptr(matrix));
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER: Compile-time error: Type: " << type << "\n" << infoLog << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER: Link-time error: Type: " << type << "\n" << infoLog << std::endl;
        }
    }
}