#include <cstring>

#include "texture.h"
#include "guaimage.h"


Texture::Texture(const char *path) {
    GuaImage image = GuaImage(path);
    int w = image.width;
    int h = image.height;
    uint32_t *pixels = new uint32_t[w * h];
    memcpy(pixels, image.pixels, sizeof(uint32_t) * w * h);

    _pixels = pixels;
    _width = w;
    _height = h;
}

Color
Texture::sample(float u, float v) const {
    if (_pixels != NULL) {
        int tu = abs((int)(u * (_width - 1)));
        int tv = abs((int)(v * (_height - 1)));

        int index = tu + tv * _width;
        Color c = Color(_pixels[index]);
        
        return c;
    } else {
        return Color();
    }
}
