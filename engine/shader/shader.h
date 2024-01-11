#pragma once

#include "shared/shared.h"
#include "math/vector/vector.h"
#include "math/matrix/matrix.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

namespace Betoneira
{
    class Shader
    {
    public:
        unsigned int id;

        Shader();
        
        // sets the current shader as active
        Shader& use();

        // compiles the shader from given source code
        void compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource=nullptr); // note: geometry source code is optional 

        void setFloat(const char* name, float value, bool useShader=false);
        void setInteger(const char* name, int value, bool useShader=false);
        void setVector2f(const char* name, float x, float y, bool useShader=false);
        void setVector2f(const char* name, const Math::Vector2f& value, bool useShader=false);
        void setVector3f(const char* name, float x, float y, float z, bool useShader=false);
        void setVector3f(const char* name, const Math::Vector3f& value, bool useShader=false);
        void setVector4f(const char* name, float x, float y, float z, float w, bool useShader=false);
        void setVector4f(const char* name, const Math::Vector4f& value, bool useShader=false);
        void setMatrix4f(const char* name, const Math::Matrix4f& matrix, bool useShader=false);
    
    private:
        void checkCompileErrors(unsigned int shader, std::string type);
    };
}