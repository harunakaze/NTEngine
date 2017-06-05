#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void logMessage(const char *formatStr, ...);
GLuint loadShader(GLenum type, char * filename);
GLuint loadProgram(GLuint vertexShader, GLuint fragmentShader);