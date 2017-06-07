#include "ResourceManager.h"

void ResourceManager::Init()
{
	//Load Model
	//Segitiga
	models.push_back(new Model("../resources/models/kotak.mif")); // 0

	//Load Texture
	//Grass
	textures.push_back(new Texture("../resources/textures/bg_menu.bmp")); // 0
	textures.push_back(new Texture("../resources/textures/ic_su_start_alpha.bmp")); // 1

	//Load Shaders
	//Normal
	shaders.push_back(new Shaders("../resources/shaders/NormalVS.vs", "../resources/shaders/NormalFS.fs")); // 0
}

//Get data

Model * ResourceManager::GetModelById(GLuint id)
{
	return models.at(id);
}

Texture * ResourceManager::GetTexById(GLuint id)
{
	return textures.at(id);
}

Shaders * ResourceManager::GetShadersById(GLuint id)
{
	return shaders.at(id);
}

//Singleton
ResourceManager * ResourceManager::RMInstance = 0;

ResourceManager * ResourceManager::getInstance()
{
	if (!RMInstance)
	{
		RMInstance = new ResourceManager();
	}

	return RMInstance;
}

void ResourceManager::destroyInstance()
{
	if (RMInstance)
	{
		delete RMInstance;
		RMInstance = NULL;
	}
}

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	for (auto &texture : textures) {
		delete texture;
	}
	for (auto &shader : shaders) {
		delete shader;
	}
}