#ifndef __Gua__canvas__
#define __Gua__canvas__

#include "vector.h"
#include "color.h"


class Canvas {
    uint32_t *_pixels;
    float _width;
    float _height;

    void putPixel(int x, int y, float z, const Color &color);

public:
    Canvas(uint32_t *pixels, float width, float height) {
        _pixels = pixels;
        _width = width;
        _height = height;
    };
    
    void clear();
    void drawPoint(const Vector &point, const Color &color);
};

#endif
