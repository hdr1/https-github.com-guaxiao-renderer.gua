#ifndef __Gua__guaimage__
#define __Gua__guaimage__


#include "color.h"


class GuaImage {
public:
    uint32_t *pixels;
    int width;
    int height;

    GuaImage(const char *path);
    
    virtual ~GuaImage() {
        delete [] pixels;
    };
};

#endif
