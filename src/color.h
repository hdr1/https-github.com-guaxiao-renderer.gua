#ifndef __Gua__color__
#define __Gua__color__


#include <cstdint>


class Color {

public:
    float r;
    float g;
    float b;
    float a;
    
    Color(float r=1.0f, float g=1.0f, float b=1.0f, float a=1.0f);
    
    uint32_t uint32() const;
};

#endif
