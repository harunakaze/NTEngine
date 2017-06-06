#include "Model.h"
#include <stdio.h>
#include <cstring>

void Model::LoadMIF(const char * fileName)
{
	FILE * pFile = NULL;

	fopen_s(&pFile, fileName, "r");

	if (pFile == NULL)
	{
		printf("FAIL TO LOAD THE DATA!\n");
		return;
	}

	fscanf_s(pFile, "VerticesCount: %d\n", &numOfVertices);

	Vertex * verticesData = new Vertex[numOfVertices];

	for (int i = 0; i < numOfVertices; i++)
	{
		fscanf_s(pFile, "%*d. pos:[%f, %f, %f]; uv:[%f, %f];\n",
			&verticesData[i].pos.x,
			&verticesData[i].pos.y,
			&verticesData[i].pos.z,
			&verticesData[i].uv.x,
			&verticesData[i].uv.y);
	}

	fscanf_s(pFile, "IndicesCount: %d\n", &indicesCount);

	GLuint * indices = new GLuint[indicesCount];

	for (int i = 0; i < indicesCount; i += 3)
	{
		fscanf_s(pFile, "%*d. %d, %d, %d\n", &indices[i], &indices[i + 1], &indices[i + 2]);
	}

	//buffer object
	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, numOfVertices * sizeof(Vertex), verticesData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//buffer indices
	glGenBuffers(1, &iboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(GLuint), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	delete[]verticesData;
	delete[]indices;

	fclose(pFile);
}

void Model::LoadNFG(const char * fileName)
{
	FILE * pFile = NULL;

	fopen_s(&pFile, fileName, "r");

	if (pFile == NULL)
	{
		printf("FAIL TO LOAD THE DATA!\n");
		return;
	}

	fscanf_s(pFile, "NrVertices: %d\n", &numOfVertices);

	Vertex * verticesData = new Vertex[numOfVertices];

	for (int i = 0; i < numOfVertices; i++)
	{
		fscanf_s(pFile, "%*d. pos:[%f, %f, %f]; norm:[%*f, %*f, %*f]; binorm:[%*f, %*f, %*f]; tgt:[%*f, %*f, %*f]; uv:[%f, %f];\n",
			&verticesData[i].pos.x,
			&verticesData[i].pos.y,
			&verticesData[i].pos.z,
			&verticesData[i].uv.x,
			&verticesData[i].uv.y);
	}

	fscanf_s(pFile, "NrIndices: %d\n", &indicesCount);

	GLuint * indices = new GLuint[indicesCount];

	for (int i = 0; i < indicesCount; i += 3)
	{
		fscanf_s(pFile, "%*d. %d, %d, %d\n", &indices[i], &indices[i + 1], &indices[i + 2]);
	}

	//buffer object
	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ARRAY_BUFFER, vboId);
	glBufferData(GL_ARRAY_BUFFER, numOfVertices * sizeof(Vertex), verticesData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//buffer indices
	glGenBuffers(1, &iboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesCount * sizeof(GLuint), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	delete[]verticesData;
	delete[]indices;

	fclose(pFile);
}

void Model::InitModel(const char * fileName) {
	if (strstr(fileName, ".nfg")) {
		LoadNFG(fileName);
	}
	else if (strstr(fileName, ".mif")) {
		LoadMIF(fileName);
	}
	else {
		printf("INVALID MODEL FILE!\n");
	}
}

Model::Model(const char * fileName)
{
	InitModel(fileName);
}

Model::~Model()
{
	glDeleteBuffers(1, &vboId);
	glDeleteBuffers(1, &iboId);
}
