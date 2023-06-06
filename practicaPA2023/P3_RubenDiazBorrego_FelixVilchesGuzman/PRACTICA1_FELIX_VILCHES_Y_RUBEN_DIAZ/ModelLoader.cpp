
#include "ModelLoader.h"
using namespace std;



void ModelLoader::calcBoundaries(Vector3D vectorPoint)
{

	this->maxX = fmax(this->maxX, vectorPoint.GetX());
	this->maxY = fmax(this->maxY, vectorPoint.GetY());
	this->maxZ = fmax(this->maxZ, vectorPoint.GetZ());

	this->minX = fmin(this->minX, vectorPoint.GetX());
	this->minY = fmin(this->minY, vectorPoint.GetY());
	this->minZ = fmin(this->minZ, vectorPoint.GetZ());

}

Triangle ModelLoader::center(Triangle t) {
	Vector3D modelCenter(this->minX + this->getWidth() / 2.0,
		this->minY + this->getHeight() / 2.0,
		this->minZ + this->getLength() / 2.0);

	Triangle centeredTriangle(
		t.getP0() - modelCenter,
		t.getP1() - modelCenter,
		t.getP2() - modelCenter,
		t.getN0(),
		t.getN1(),
		t.getN2());

	return centeredTriangle;
}

void ModelLoader::LoadModel(const string& filePath) {
	try {
		ifstream objFile(filePath);
		string line;
		if (objFile.is_open()) 
		{
			int count = 0;
			while (getline(objFile, line)) 
			{
				if (line[0] == 'v' && line[1] == 'n') 
				{
					Vector3D normal = this->parseObjLineToVector3D(line);
					this->normales.push_back(normal);
				}
				else if (line[0] == 'v') 
				{
					Vector3D vertex = this->parseObjLineToVector3D(line);
					//cout << vertex.GetY() << endl;
					this->calcBoundaries(vertex);

					this->Vertex.push_back(vertex);
				}
				else if (line[0] == 'f') 
				{
					Triangle triangle = this->parseObjTriangle(line);
					this->modelo.AddTriangles(this->center(triangle));
				}
			}
			objFile.close();
		}
		else {
			cout << "No se ha podido abrir el archivo: " << filePath << endl;
		}
	}
	catch (exception& ex) {
		cout << "Excepción al procesar el archivo: " << filePath << endl;
		cout << ex.what() << endl;
	}
}


Vector3D ModelLoader::parseObjLineToVector3D(const string& line) {
	string typeOfPoint;
	float xCoord, yCoord, zCoord;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoord >> yCoord >> zCoord;
	Vector3D vectorPoint(xCoord, yCoord, zCoord);
	return vectorPoint * this->getScale();
}


Triangle  ModelLoader::parseObjTriangle(const string& s) {
	char c;
	int idxV1, idxV2, idxV3;
	int idxN1, idxN2, idxN3;

	istringstream stringStream(s);
	stringStream >> c;
	stringStream >> idxV1 >> c >> c >> idxN1;
	stringStream >> idxV2 >> c >> c >> idxN2;
	stringStream >> idxV3 >> c >> c >> idxN3;

	Vector3D vert0 = this->Vertex[idxV1 - 1];
	Vector3D vert1 = this->Vertex[idxV2 - 1];
	Vector3D vert2 = this->Vertex[idxV3 - 1];
	Vector3D normal = this->normales[idxN1 - 1]; //las tres normales son iguales

	Triangle parsedTriangle(vert0, vert1, vert2, normal, normal, normal);

	return parsedTriangle;
}

