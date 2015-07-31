#ifndef __Gua__vector__
#define __Gua__vector__


#include "guamath.h"


class Vector {
public:
    float x;
    float y;
    float z;
    
    Vector(float x=0.0f, float y=0.0f, float z=0.0f) {
        this->x = x;
        this->y = y;
        this->z = z;
    };
    
    float length() const;
    Vector normalize() const;
    float dot(const Vector &v) const;
    Vector cross(const Vector &v) const;
    Vector interpolate(const Vector &v, float factor) const;
    
    Vector operator+(const Vector &v) const {
        return Vector(x + v.x, y + v.y, z + v.z);
    };
    
    Vector operator-(const Vector &v) const {
        return Vector(x - v.x, y - v.y, z - v.z);
    };
    
    Vector operator*(float factor) const {
        return Vector(x * factor, y * factor, z * factor);
    };

    bool operator==(const Vector &v) const {
        return floatEqual(x, v.x) && floatEqual(y, v.y) && floatEqual(z, v.z);
    };
};

#endif
