#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Utilities/Utilities.h"

class Shaders
{
public:
	GLuint program, vertexShader, fragmentShader;
	char fileVS[260];
	char fileFS[260];
	GLint positionAttribute;
	GLint colorAttribute;

	int Init(char * fileVertexShader, char * fileFragmentShader);
	~Shaders();
};