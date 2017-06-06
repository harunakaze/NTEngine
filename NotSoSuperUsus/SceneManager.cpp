#include "SceneManager.h"

//Init
void SceneManager::Init() {

	// Init camera
	cameraInit();

	//Player
	GameObject *player = new GameObject();
	player->model = ResourceManager::getInstance()->GetModelById(0);
	player->texture = ResourceManager::getInstance()->GetTexById(0);
	player->shaders = ResourceManager::getInstance()->GetShadersById(0);
	player->position.x = 0;
	player->position.y = 0;
	player->position.z = 0;

	player->rotation.x = 0;
	player->rotation.y = 0;
	player->rotation.z = 0;

	player->scale.x = 1.0;
	player->scale.y = 1.0;
	player->scale.z = 1.0;

	player->UpdateWorldMatrix();

	gameObjects.push_back(player);

	player = new GameObject();
	player->model = ResourceManager::getInstance()->GetModelById(0);
	player->texture = ResourceManager::getInstance()->GetTexById(1);
	player->shaders = ResourceManager::getInstance()->GetShadersById(0);
	player->position.x = -1.5;
	player->position.y = 0;
	player->position.z = 0;

	player->rotation.x = 0;
	player->rotation.y = 0;
	player->rotation.z = 0;

	player->scale.x = 1.0;
	player->scale.y = 1.0;
	player->scale.z = 1.0;

	player->UpdateWorldMatrix();

	gameObjects.push_back(player);
}

//Update
void SceneManager::Update(double deltaTime) {

	//camera->rotateRight(deltaTime / 600.0);

	for (auto &go : gameObjects) {
		//go->rotation.y += 0.7 * deltaTime;
		//go->UpdateWorldMatrix();
		go->Update(deltaTime);
	}
}

//Draw
void SceneManager::Draw() {
	for (auto &go : gameObjects) {
		go->Draw();
	}
}

//Camera

void SceneManager::cameraInit()
{
	camera = new Camera();
}

//Singleton stuff
SceneManager * SceneManager::SMInstance = 0;

SceneManager * SceneManager::getInstance()
{
	if (!SMInstance)
	{
		SMInstance = new SceneManager();
	}

	return SMInstance;
}

void SceneManager::destroyInstance()
{
	if (SMInstance)
	{
		delete SMInstance;
		SMInstance = NULL;
	}
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	//delete camera;
	for (auto &go : gameObjects) {
		delete go;
	}
}