#pragma once
#include "../Utilities/utilities.h"
#include "Vertex.h"

class Model
{
public:
	Model(const char * fileName);
	~Model();
	void InitModel(const char * fileName);

	GLuint vboId;
	GLuint iboId;
	GLuint indicesCount;
	GLuint numOfVertices;

private:
	void LoadMIF(const char * fileName);
	void LoadNFG(const char * fileName);

};