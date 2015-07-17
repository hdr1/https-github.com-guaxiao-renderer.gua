#ifndef __Gua__vector__
#define __Gua__vector__


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
};

#endif
