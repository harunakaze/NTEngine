#pragma once
#include "../Utilities/utilities.h"
enum Wrap
{
	REPEAT,
	CLAMP_TO_EDGE,
	MIRRORED_REPEAT
};
class Texture
{
public:
	GLuint idTexture;
	Wrap wrapMode;

	void initTexture(const char * fileName);

	Texture(const char * fileName);
	~Texture();
};