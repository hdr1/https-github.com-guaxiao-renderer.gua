#ifndef __Gua__canvas__
#define __Gua__canvas__

#include "vector.h"
#include "color.h"
#include "vertex.h"
#include "matrix.h"
#include "mesh.h"


class Canvas {
    uint32_t *_pixels;
    float *_depthBuffer;
    
    int _bufferSize;
    
    float _width;
    float _height;

    void putPixel(int x, int y, float z, const Color &color);
    void drawScanline(const Vertex &v1, const Vertex &v2, int y, const Texture *texture);
    Vertex project(const Vertex &v, const Matrix &transform) const;

public:
    Canvas(uint32_t *pixels, float width, float height) {
        _pixels = pixels;
        _width = width;
        _height = height;
        
        _bufferSize = width * height;
        _depthBuffer = new float[_bufferSize];
    };
    
    virtual ~Canvas() {
        delete [] _depthBuffer;
    };
    
    void clear();
    
    void drawPoint(const Vector &point, const Color &color);
    void drawLine(const Vertex &v1, const Vertex &v2);
    void drawTriangle(const Vertex &v1, const Vertex &v2, const Vertex &v3, const Texture *texture);
    void drawMesh(const Mesh &mesh);

};

#endif
