#include "canvas.h"

#include <cstring>


void
Canvas::clear() {
    memset(_pixels, 0, sizeof(uint32_t) * _width * _height);
}

void
Canvas::putPixel(int x, int y, float z, const Color &color) {
    int index = (int)(_width * y + x);
        
    _pixels[index] = color.uint32();
}

void
Canvas::drawPoint(const Vector &point, const Color &color) {
    if (point.x >= 0 && point.y >= 0 &&
        point.x < _width && point.y < _height) {
        putPixel(point.x, point.y, point.z, color);
    }
}
