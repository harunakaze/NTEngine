#include "Texture.h"
#include <stdio.h>
#include <cstring>

void Texture::initTexture(const char * fileName)
{

	GLuint idTextureLoad;
	int width, height, bpp;
	char * imageData;

	if (strstr(fileName, ".tga")) {
		imageData = LoadTGA(fileName, &width, &height, &bpp);
	}
	else if (strstr(fileName, ".bmp")) {
		imageData = load_bmp(fileName, &width, &height, &bpp);
	}

	if (imageData == NULL)
	{
		printf("FAIL TO LOAD IMAGE DATA!\n");
		return;
	}

	glGenTextures(1, &idTextureLoad);
	glBindTexture(GL_TEXTURE_2D, idTextureLoad);

	if (bpp == 24)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
	}

	if (wrapMode == Wrap::CLAMP_TO_EDGE)
	{
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); //GL_CLAMP_TO_EDGE //GL_MIRRORED_REPEAT
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); //GL_CLAMP_TO_EDGE //GL_MIRRORED_REPEAT
	}

	if (wrapMode == Wrap::MIRRORED_REPEAT)
	{
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT); //GL_CLAMP_TO_EDGE //GL_MIRRORED_REPEAT
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT); //GL_CLAMP_TO_EDGE //GL_MIRRORED_REPEAT
	}

	if (wrapMode == Wrap::REPEAT)
	{
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT); //GL_CLAMP_TO_EDGE //GL_MIRRORED_REPEAT
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT); //GL_CLAMP_TO_EDGE //GL_MIRRORED_REPEAT
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	delete imageData;

	idTexture = idTextureLoad;
}

Texture::Texture(const char * fileName)
{
	wrapMode = Wrap::CLAMP_TO_EDGE;
	initTexture(fileName);
}

Texture::~Texture()
{
	glDeleteTextures(1, &idTexture);
}