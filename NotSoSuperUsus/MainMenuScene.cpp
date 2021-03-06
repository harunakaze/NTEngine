#include "MainMenuScene.h"
#include "SceneFSM.h"

void MainMenuScene::Init() {
	//Player
	GameObject *object = new GameObject();

	//BG
	object->model = ResourceManager::getInstance()->GetModelById(0);
	object->texture = ResourceManager::getInstance()->GetTexById(0);
	object->shaders = ResourceManager::getInstance()->GetShadersById(0);
	object->position.x = -2.3;
	object->position.y = 2.3;
	object->position.z = 0;

	object->rotation.x = 0;
	object->rotation.y = 0;
	object->rotation.z = 0;

	object->scale.x = 4.7;
	object->scale.y = 4.6;
	object->scale.z = 1;

	object->UpdateWorldMatrix();

	gameObjects.push_back(object);
}

void MainMenuScene::Update(double deltaTime) {
	SceneManager::Update(deltaTime);
}