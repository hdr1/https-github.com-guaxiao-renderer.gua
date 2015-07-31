#ifndef __Gua__mesh__
#define __Gua__mesh__


#include <vector>

#include "vertex.h"
#include "texture.h"


class Mesh {
public:
    Vector position;
    Vector rotation;
    Vector scale;
    
    std::vector<Vertex> vertices;
    std::vector<int> indices;
    
    Texture *texture;
    
    Mesh() {
        position = Vector(0, 0, 0);
        rotation = Vector(0, 0, 0);
        scale = Vector(1, 1, 1);
    };

    Mesh(const char *path, const char *texturePath);
    
    virtual ~Mesh() {
        delete texture;
    };
};

#endif
