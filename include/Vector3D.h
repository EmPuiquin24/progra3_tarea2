#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D {
private:
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
public:
    Vector3D() = default;
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    friend Vector3D operator+(const Vector3D& a, const Vector3D& b) {
        return {a.x + b.x, a.y + b.y, a.z + b.z};
    }

    Vector3D& operator+=(const Vector3D& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    friend Vector3D operator-(const Vector3D& a, const Vector3D& b) {
        return {a.x - b.x, a.y - b.y, a.z - b.z};
    }

    friend Vector3D operator*(const Vector3D& a, const Vector3D& b) {
        return {a.x * b.x, a.y * b.y, a.z * b.z};
    }

    friend Vector3D operator/(const Vector3D& a, std::size_t n) {
        return {a.x / n, a.y / n, a.z / n};
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
};

#endif // VECTOR3D_H