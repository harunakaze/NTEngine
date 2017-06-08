#pragma once
#include "../Utilities/utilities.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include <vector>

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	//Main Function
	virtual void Init();

	virtual void Enter();
	virtual void Draw();
	virtual void Update(double deltaTime);
	virtual void Exit();

protected:
	//Game Object
	std::vector<GameObject*> gameObjects;
};