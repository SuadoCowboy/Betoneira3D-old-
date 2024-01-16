#include "matrix.h"

#include <math.h>

using namespace Betoneira;

// https://stackoverflow.com/a/51683425

Math::Matrix4f::Matrix4f(){}

Math::Matrix4f::~Matrix4f(){}

const float* Math::matrixDataPointer(const Math::Matrix4f& matrix)
{
    return matrix.elements.data();
}

Math::Matrix4f& Math::multiply(Math::Matrix4f& matrix, const Math::Matrix4f& multiplierMatrix)
{
    // multiply the existing matrix by the new and store the result in a buffer
    const float* A = matrixDataPointer(matrix);
    const float* B = matrixDataPointer(multiplierMatrix);
    std::array<float, 16> C;

    for (int k = 0; k < 4; ++ k) {
        for (int j = 0; j < 4; ++ j) {
            C[k*4+j] =
                A[0*4+j] * B[k*4+0] +
                A[1*4+j] * B[k*4+1] +
                A[2*4+j] * B[k*4+2] +
                A[3*4+j] * B[k*4+3];
        }
    }

    // copy the buffer to the attribute
    matrix.elements = C;

    return matrix;
}

Math::Matrix4f& Math::translate(Math::Matrix4f& matrix, const Math::Vector3f& translation)
{
    float x = translation.x;
    float y = translation.y;
    float z = translation.z;

    Matrix4f transMat;
    transMat.elements = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        x,    y,    z,    1.0f
    };

    return multiply(matrix, transMat);
}

Math::Matrix4f& Math::scale(Math::Matrix4f& matrix, const Math::Vector3f& scaler)
{
    float x = scaler.x;
    float y = scaler.y;
    float z = scaler.z;

    Matrix4f scaleMat;
    scaleMat.elements = {
        x,    0.0f, 0.0f, 0.0f,
        0.0f, y,    0.0f, 0.0f,
        0.0f, 0.0f, z,    0.0f,
        0.0f, 0.0f, 0.0f, 1.0f };

    return multiply(matrix, scaleMat);
}

Math::Matrix4f& Math::rotate(Math::Matrix4f& matrix, float angle, const Math::Vector3f& axis)
{
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    float c = cos(angle);
    float s = -sin(angle);

    Matrix4f rotationMat;
    rotationMat.elements = {
       x*x*(1.0f-c)+c,   x*y*(1.0f-c)-z*s, x*z*(1.0f-c)+y*s, 0.0f,
       y*x*(1.0f-c)+z*s, y*y*(1.0f-c)+c,   y*z*(1.0f-c)-x*s, 0.0f,
       z*x*(1.0f-c)-y*s, z*y*(1.0f-c)+x*s, z*z*(1.0f-c)+c,   0.0f,
       0.0f,             0.0f,             0.0f,             1.0f
    };

    return multiply(matrix, rotationMat);
}