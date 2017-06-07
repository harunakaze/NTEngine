#include "SceneFSM.h"

void SceneFSM::InitFSM() {
	mainMenuScene = new MainMenuScene();


	currentScene = mainMenuScene;
}

void SceneFSM::Update(double deltaTime) {
	if (exitCurrentState) {
		currentScene->Exit();

		exitCurrentState = false;
		enterNextState = true;

		currentScene = nextScene;
	}

	if (enterNextState) {
		currentScene->Init();

		enterNextState = false;
	}

	currentScene->Update(deltaTime);
}

void SceneFSM::Draw() {
	currentScene->Draw();
}

void SceneFSM::SwitchScene(const char * sceneName) {
	if (sceneName == "MainMenuScene") {
		nextScene = mainMenuScene;
	}
}

//Singleton stuff
SceneFSM * SceneFSM::objectInstance = 0;

SceneFSM * SceneFSM::getInstance() {
	if (!objectInstance) {
		objectInstance = new SceneFSM();
	}

	return objectInstance;
}

void SceneFSM::destroyInstance() {
	if (objectInstance) {
		delete objectInstance;
		objectInstance = nullptr;
	}
}

SceneFSM::SceneFSM() {

}

SceneFSM::~SceneFSM() {

}