#pragma once
#include "Model.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class ModelLoader
{
private:
    float scale;
    Model modelo;
    vector<Vector3D> Vertex;
    vector<Vector3D> normales;
    float maxX, maxY, maxZ, minX, minY, minZ;
    float getWidth() { return maxX - minX; }
    float getHeight() { return maxY - minY; }
    float getLength() { return maxZ - minZ; }
    void calcBoundaries(Vector3D vectorPoint);
    Triangle center(Triangle t);
    Vector3D parseObjLineToVector3D(const string& s);
    Triangle parseObjTriangle(const string& s);

public:
    ModelLoader() : scale(1) {}
    inline Model getModelo() { return modelo; }
    inline float getScale() { return scale; }
    inline void setEscala(float es) { scale = es; }
    void LoadModel(const string& filePath);
    inline void Clear() {
        Vertex.clear();
        normales.clear();
        modelo.Clear();
    }
};