//-----------------------------------------------------------------------------
// File: CGameFramework.cpp
//-----------------------------------------------------------------------------

#include "stdafx.h"
#include "OBJLoader.h"

void COBJLoader::ParseVertex(std::stringstream& sin, std::vector<CVertex>& vertices)
{
    float x, y, z;
    sin >> x >> y >> z;
    vertices.emplace_back(x, y, z);
}

void COBJLoader::ParseFace(std::stringstream& sin, std::vector<CFace>& faces, std::vector<CVertex>& vertices)
{
    std::string token;
    CFace face;
    while (sin >> token)
    {
        std::stringstream faceToken(token);
        std::string vertexIndex;
        std::getline(faceToken, vertexIndex, '/');
        int index = std::stoi(vertexIndex) - 1; // OBJ indexing starts at 1
        face.vertices.push_back(index);
    }
    faces.push_back(face);
}

CMesh* COBJLoader::Load(const std::string& filename)
{
    std::ifstream fin(filename);
    if (!fin.is_open())
    {
        throw std::runtime_error("Could not open OBJ file: " + filename);
    }

    std::vector<CVertex> vertices;
    std::vector<CFace> faces;
    std::string line;

    while (getline(fin, line))
    {
        std::stringstream s(line);
        std::string type;
        s >> type;
        if (type == "v")
        {
            ParseVertex(s, vertices);
        }
        else if (type == "f")
        {
            ParseFace(s, faces, vertices);
        }
    }

    CMesh* mesh = new CMesh(faces.size());
    for (size_t i = 0; i < faces.size(); i++)
    {
        CPolygon* polygon = new CPolygon(faces[i].vertices.size());
        for (size_t j = 0; j < faces[i].vertices.size(); j++)
        {
            polygon->SetVertex(j, vertices[faces[i].vertices[j]]);
        }
        mesh->SetPolygon(i, polygon);
    }

    return mesh;
}