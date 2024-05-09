#pragma once

#include "Mesh.h"
#include "Camera.h"

//class CVertex
//{
//public:
//    float x, y, z;
//    CVertex(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
//};

class CFace
{
public:
    std::vector<int> vertices; // indices of the vertices
};

class COBJLoader
{
public:
    static CMesh* Load(const std::string& filename);
private:
    static void ParseVertex(std::stringstream& sin, std::vector<CVertex>& vertices);
    static void ParseFace(std::stringstream& sin, std::vector<CFace>& faces, std::vector<CVertex>& vertices);
};