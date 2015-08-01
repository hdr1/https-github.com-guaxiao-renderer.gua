#include <fstream>
#include <string>

#include "mesh.h"
#include "guafoundation.h"


Mesh::Mesh(const char *path, const char *texturePath) {
    position = Vector(0, 0, 0);
    rotation = Vector(0, 0, 0);
    scale = Vector(1, 1, 1);
    
    texture = new Texture(texturePath);

    // load gua3d format, version 1.1
    const char delimiter = ' ';
    std::ifstream guaFile(path);
    std::string line;
    
    // eat file descriptor and version
    getline(guaFile, line);
    getline(guaFile, line);
    
    getline(guaFile, line);
    auto vs = split(line, delimiter);
    int numberOfVertices = atoi(vs[1].c_str());
    
    getline(guaFile, line);
    auto ts = split(line, delimiter);
    int numberOfTriangles = atoi(ts[1].c_str());
    
    // vertices
    for (int i = 0; i < numberOfVertices; i++) {
        getline(guaFile, line);
        auto vs = split(line, delimiter);
        float x = atof(vs[0].c_str());
        float y = atof(vs[1].c_str());
        float z = atof(vs[2].c_str());
        
        float nx = atof(vs[3].c_str());
        float ny = atof(vs[4].c_str());
        float nz = atof(vs[5].c_str());
        
        float u = atof(vs[6].c_str());
        float v = atof(vs[7].c_str());
        vertices.push_back(Vertex(Vector(x, y, z), Vector(nx, ny, nz), u, v, Color::randomColor()));
    }
    
    // triangles
    for (int i = 0; i < numberOfTriangles; i++) {
        getline(guaFile, line);
        auto t = split(line, delimiter);
        int a = atof(t[0].c_str());
        int b = atof(t[1].c_str());
        int c = atof(t[2].c_str());
        indices.push_back(a);
        indices.push_back(b);
        indices.push_back(c);
    }
    
    guaFile.close();
}