#pragma once
#include "../Utilities/utilities.h"
#include "GameObject.h"
#include "Camera.h"
#include "ResourceManager.h"
#include <vector>

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	//Main Function
	void Init();
	void Draw();
	void Update(double deltaTime);

	//Camera
	Camera * camera;

	//Singleton stuff
	static SceneManager * getInstance();
	static void destroyInstance();
private:
	//Game Object
	std::vector<GameObject*> gameObjects;

	//Camera
	void cameraInit();

	//Singleton Stuff
	static SceneManager * SMInstance;
};