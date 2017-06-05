#include "MainUtil.h"
#include <stdio.h>
#include <stdlib.h>

GLuint loadShader(GLenum type, char * filename) {
	GLuint shader;
	GLint compiled;

	// Create shader object
	shader = glCreateShader(type);

	if (shader == 0)
		return 0;

	// Load source
	FILE * pf;
	if (fopen_s(&pf, filename, "rb") != 0) {
		logMessage("Error opening file.");
		return NULL;
	}
	fseek(pf, 0, SEEK_END);
	long size = ftell(pf);
	fseek(pf, 0, SEEK_SET);

	char * shaderSrc = new char[size + 1];
	fread(shaderSrc, sizeof(char), size, pf);
	shaderSrc[size] = 0;
	fclose(pf);

	glShaderSource(shader, 1, (const char **)&shaderSrc, NULL);
	delete[] shaderSrc;

	// Compile shader
	glCompileShader(shader);

	// Check compile status
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

	if (!compiled)
	{
		GLint infoLen = 0;

		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

		if (infoLen > 1)
		{
			char* infoLog = new char[infoLen];

			glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
			logMessage("Error compiling shader:\n%s\n", infoLog);

			delete[] infoLog;
		}

		glDeleteShader(shader);
		return 0;
	}

	return shader;
}

GLuint loadProgram(GLuint vertexShader, GLuint fragmentShader) {
	GLuint programObject;
	GLint linked;

	// Create program object
	programObject = glCreateProgram();

	if (programObject == 0)
		return 0;

	glAttachShader(programObject, vertexShader);
	glAttachShader(programObject, fragmentShader);

	// Link program
	glLinkProgram(programObject);

	// Check link status
	glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

	if (!linked)
	{
		GLint infoLen = 0;

		glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

		if (infoLen > 1)
		{
			char* infoLog = new char[sizeof(char) * infoLen];

			glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
			logMessage("Error linking program:\n%s\n", infoLog);

			delete infoLog;
		}

		glDeleteProgram(programObject);
		return 0;
	}

	return programObject;
}