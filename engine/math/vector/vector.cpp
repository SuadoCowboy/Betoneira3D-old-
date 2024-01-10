#include "math/vector/vector.h"

using namespace Betoneira::Math;

// Vector2

template <typename T>
Vector2<T>::Vector2() : x(0), y(0) {}

template <typename T>
Vector2<T>::Vector2(T _x, T _y) : x(_x), y(_y){}

template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) const {
    return Vector2<T>(x + other.x, y + other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) const {
    return Vector2<T>(x - other.x, y - other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator*(const T& scalar) const {
    return Vector2<T>(x * scalar, y * scalar);
}

template <typename T>
Vector2<T>& Vector2<T>::operator*=(const T& scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator/(const T& scalar) const {
    return Vector2<T>(x / scalar, y / scalar);
}

template <typename T>
Vector2<T>& Vector2<T>::operator/=(const T& scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& other) {
    x += other.x;
    y += other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

template <typename T>
bool Vector2<T>::operator==(const Vector2<T>& other) const {
    return (x == other.x) && (y == other.y);
}

template <typename T>
bool Vector2<T>::operator!=(const Vector2<T>& other) const {
    return !(*this == other);
}

// Vector3

template <typename T>
Vector3<T>::Vector3(){}

template <typename T>
Vector3<T>::Vector3(T _x, T _y, T _z) : x(_x), y(_y), z(_z){}

template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T>& other) const
{
    return Vector3<T>(x + other.x, y + other.y, z + other.z);
}

template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T>& other) const
{
    return Vector3<T>(x - other.x, y - other.y, z - other.z);
}

template <typename T>
Vector3<T> Vector3<T>::operator*(const T& scalar) const
{
    return Vector3<T>(x * scalar, y * scalar, z * scalar);
}

template <typename T>
Vector3<T>& Vector3<T>::operator*=(const T& scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator/(const T& scalar) const
{
    return Vector3<T>(x / scalar, y / scalar, z / scalar);
}

template <typename T>
Vector3<T>& Vector3<T>::operator/=(const T& scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template <typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template <typename T>
bool Vector3<T>::operator==(const Vector3<T>& other) const
{
    return (x == other.x) && (y == other.y) && (z == other.z);
}

template <typename T>
bool Vector3<T>::operator!=(const Vector3<T>& other) const
{
    return !(*this == other);
}

// Vector4

template <typename T>
Vector4<T>::Vector4(){}

template <typename T>
Vector4<T>::Vector4(T _x, T _y, T _z, T _w) : x(_x), y(_y), w(_w){}

template <typename T>
Vector4<T> Vector4<T>::operator+(const Vector4<T>& other) const
{
    return Vector4<T>(x + other.x, y + other.y, z + other.z, w + other.w);
}

template <typename T>
Vector4<T> Vector4<T>::operator-(const Vector4<T>& other) const
{
    return Vector4<T>(x - other.x, y - other.y, z - other.z, w - other.w);
}

template <typename T>
Vector4<T> Vector4<T>::operator*(const T& scalar) const
{
    return Vector4<T>(x * scalar, y * scalar, z * scalar, w * scalar);
}

template <typename T>
Vector4<T>& Vector4<T>::operator*=(const T& scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

template <typename T>
Vector4<T> Vector4<T>::operator/(const T& scalar) const
{
    return Vector4<T>(x / scalar, y / scalar, z / scalar, w / scalar);
}

template <typename T>
Vector4<T>& Vector4<T>::operator/=(const T& scalar)
{
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}

template <typename T>
Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

template <typename T>
Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

template <typename T>
bool Vector4<T>::operator==(const Vector4<T>& other) const
{
    return (x == other.x) && (y == other.y) && (z == other.z);
}

template <typename T>
bool Vector4<T>::operator!=(const Vector4<T>& other) const
{
    return !(*this == other);
}

template class Vector2<float>;
template class Vector2<unsigned int>;
template class Vector2<int>;

template class Vector3<float>;
template class Vector3<unsigned int>;
template class Vector3<int>;

template class Vector4<float>;
template class Vector4<unsigned int>;
template class Vector4<int>;