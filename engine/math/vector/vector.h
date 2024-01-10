#pragma once

#include <string>
#include <sstream>

namespace Betoneira::Math
{
    template <typename T>
    class Vector2
    {
    public:
        Vector2();
        Vector2(T x, T y);

        T x;
        T y;

        // made by ChatGPT xd...
        Vector2<T> operator+(const Vector2<T>& other) const;
        Vector2<T> operator-(const Vector2<T>& other) const;
        Vector2<T> operator*(const T& scalar) const;
        Vector2<T>& operator*=(const T& scalar);
        Vector2<T> operator/(const T& scalar) const;
        Vector2<T>& operator/=(const T& scalar);
        Vector2<T>& operator+=(const Vector2<T>& other);
        Vector2<T>& operator-=(const Vector2<T>& other);
        bool operator==(const Vector2<T>& other) const;
        bool operator!=(const Vector2<T>& other) const;
    };
    
    template <typename T>
    class Vector3
    {
    public:
        Vector3();
        Vector3(T x, T y, T z);

        T x;
        T y;
        T z;

        Vector3<T> operator+(const Vector3<T>& other) const;
        Vector3<T> operator-(const Vector3<T>& other) const;
        Vector3<T> operator*(const T& scalar) const;
        Vector3<T>& operator*=(const T& scalar);
        Vector3<T> operator/(const T& scalar) const;
        Vector3<T>& operator/=(const T& scalar);
        Vector3<T>& operator+=(const Vector3<T>& other);
        Vector3<T>& operator-=(const Vector3<T>& other);
        bool operator==(const Vector3<T>& other) const;
        bool operator!=(const Vector3<T>& other) const;
    };

    template <typename T>
    class Vector4
    {
    public:
        Vector4();
        Vector4(T x, T y, T z, T w);

        T x;
        T y;
        T z;
        T w;

        Vector4<T> operator+(const Vector4<T>& other) const;
        Vector4<T> operator-(const Vector4<T>& other) const;
        Vector4<T> operator*(const T& scalar) const;
        Vector4<T>& operator*=(const T& scalar);
        Vector4<T> operator/(const T& scalar) const;
        Vector4<T>& operator/=(const T& scalar);
        Vector4<T>& operator+=(const Vector4<T>& other);
        Vector4<T>& operator-=(const Vector4<T>& other);
        bool operator==(const Vector4<T>& other) const;
        bool operator!=(const Vector4<T>& other) const;
    };
    
    typedef Vector2<int> Vector2i;
    typedef Vector2<unsigned int> Vector2u;
    typedef Vector2<float> Vector2f;

    typedef Vector3<int> Vector3i;
    typedef Vector3<unsigned int> Vector3u;
    typedef Vector3<float> Vector3f;
    
    typedef Vector4<int> Vector4i;
    typedef Vector4<unsigned int> Vector4u;
    typedef Vector4<float> Vector4f;
    
    template <typename T>
    std::string vector2ToString(const Vector2<T>& vector)
    {
        std::ostringstream stringStream;
        stringStream << "(" << vector.x << ", " << vector.y << ")";
        return stringStream.str();
    }

    template <typename T>
    std::string vector3ToString(const Vector3<T>& vector)
    {
        std::ostringstream stringStream;
        stringStream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
        return stringStream.str();
    }

    template <typename T>
    std::string vector4ToString(const Vector4<T>& vector)
    {
        std::ostringstream stringStream;
        stringStream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
        return stringStream.str();
    }
}