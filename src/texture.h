#ifndef __Gua__texture__
#define __Gua__texture__


#include "Color.h"


class Texture {
    uint32_t *_pixels;
    int _width;
    int _height;
    
public:
    Texture(const char *path);
    
    virtual ~Texture() {
        delete [] _pixels;
    };
    
    Color sample(float u, float v) const;
};

#endif
