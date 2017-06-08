#include "GameplayScene.h"
#include "SceneFSM.h"

void GamePlayScene::Init() {
	//Player
	GameObject *object = new GameObject();

	//Logo
	object->model = ResourceManager::getInstance()->GetModelById(0);
	object->texture = ResourceManager::getInstance()->GetTexById(1);
	object->shaders = ResourceManager::getInstance()->GetShadersById(0);
	object->position.x = -1.5;
	object->position.y = 0;
	object->position.z = 0;

	object->rotation.x = 0;
	object->rotation.y = 0;
	object->rotation.z = 0;

	object->scale.x = 1.0;
	object->scale.y = 1.0;
	object->scale.z = 1.0;

	object->UpdateWorldMatrix();

	gameObjects.push_back(object);
}

void GamePlayScene::Update(double deltaTime) {
	SceneManager::Update(deltaTime);

}