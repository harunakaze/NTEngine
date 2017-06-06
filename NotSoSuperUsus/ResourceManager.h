#pragma once
#include "Model.h"
#include "Texture.h"
#include "Shaders.h"
#include "../Utilities/utilities.h"
#include <vector>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	//Init
	void Init();

	//Get data
	//Index = Id
	Model * GetModelById(GLuint id);
	Texture * GetTexById(GLuint id);
	Shaders * GetShadersById(GLuint id);

	//Singleton stuff
	static ResourceManager * getInstance();
	static void destroyInstance();

private:
	//Model
	std::vector<Model*> models;

	//Texture
	std::vector<Texture*> textures;

	//Shaders
	std::vector<Shaders*> shaders;

	//Singleton stuff
	static ResourceManager * RMInstance;
};