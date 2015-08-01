#include "vector.h"

    
float
Vector::length() const {
    return sqrtf(x * x + y * y + z * z);
}

Vector
Vector::normalize() const {
    float factor = 0;
    float length = this->length();
    if(length > 0) {
        factor = 1 / length;
    }
    return Vector(x * factor, y * factor, z * factor);
};

float
Vector::dot(const Vector &v) const {
    return x * v.x + y * v.y + z * v.z;
};

Vector
Vector::cross(const Vector &v) const {
    float X = y * v.z - z * v.y;
    float Y = z * v.x - x * v.z;
    float Z = x * v.y - y * v.x;
    return Vector(X, Y, Z);
};

Vector
Vector::interpolate(const Vector &v, float factor) const {
    return *this + (v - *this) * factor;
};
