#include "SceneManager.h"

//Init
void SceneManager::Init() {
	printf("Base scene manager init called, might not want this.");
}

//Exit
void SceneManager::Exit() {
	printf("Base scene manager exit called, might not want this.");
}

//Update
void SceneManager::Update(double deltaTime) {

	//camera->rotateRight(deltaTime / 600.0);

	for (auto &go : gameObjects) {
		//go->position.x -= 0.1 * deltaTime;
		//go->UpdateWorldMatrix();
		//printf("%f\n", go->position.x);
		go->Update(deltaTime);
	}
}

//Draw
void SceneManager::Draw() {
	for (auto &go : gameObjects) {
		go->Draw();
	}
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	for (auto &go : gameObjects) {
		delete go;
	}
}