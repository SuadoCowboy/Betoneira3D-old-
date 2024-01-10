#pragma once

// https://stackoverflow.com/a/51683425

#include "math/vector/vector.h"

#include <math.h>
#include <array>

namespace Betoneira::Math
{
    class Matrix4f
    {
    public:
        std::array<float, 16> elements = {
            1, 0, 0, 0, 
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };

        Matrix4f();
        ~Matrix4f();
    };

    const float* matrixDataPointer(const Matrix4f& matrix);

    Matrix4f& multiply(Matrix4f& matrix, const Matrix4f& multiplierMatrix);
    Matrix4f& translate(Matrix4f& matrix, const Vector3f& translation);
    Matrix4f& scale(Matrix4f& matrix, const Vector3f& scaler);
    Matrix4f& rotate(Matrix4f& matrix, float angle, const Vector3f& axis);
}