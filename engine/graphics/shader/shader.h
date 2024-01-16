#pragma once

#include "math/vector/vector.h"

#include <glm/glm.hpp>

#include <string>

namespace Betoneira
{
    class Shader
    {
    public:
        unsigned int id;

        Shader();
        Shader(const char* vertexFilePath, const char* fragmentFilePath, const char* geometryFilePath=nullptr);
        
        // sets the current shader as active
        Shader& use();

        // compiles the shader from given files paths
        void compileFile(const char* vertexFilePath, const char* fragmentFilePath, const char* geometryFilePath=nullptr);
        // compiles the shader from given sources
        void compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource=nullptr);

        void setFloat(const char* name, float value, bool useShader=false);
        void setInteger(const char* name, int value, bool useShader=false);
        void setVector2f(const char* name, float x, float y, bool useShader=false);
        void setVector2f(const char* name, const Math::Vector2f& value, bool useShader=false);
        void setVector3f(const char* name, float x, float y, float z, bool useShader=false);
        void setVector3f(const char* name, const Math::Vector3f& value, bool useShader=false);
        void setVector4f(const char* name, float x, float y, float z, float w, bool useShader=false);
        void setVector4f(const char* name, const Math::Vector4f& value, bool useShader=false);
        void setMatrix2x2(const char* name, const glm::mat2 &mat, bool useShader=false) const;
        void setMatrix3x3(const char* name, const glm::mat3 &mat, bool useShader=false) const;
        void setMatrix4x4(const char* name, const glm::mat4 &mat, bool useShader=false) const;
    
    private:
        void checkCompileErrors(unsigned int shader, std::string type);
    };
}