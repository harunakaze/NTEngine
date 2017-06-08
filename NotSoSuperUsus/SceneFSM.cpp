#include "SceneFSM.h"

void SceneFSM::InitFSM() {
	mainMenuScene = new MainMenuScene();
	gamePlayScene = new GamePlayScene();

	mainMenuScene->Init();
	gamePlayScene->Init();

	currentScene = mainMenuScene;
}

void SceneFSM::SwitchScene(const char * sceneName) {
	if (sceneName == "MainMenuScene") {
		SetNextScene(mainMenuScene);
	}
	else if (sceneName == "GameplayScene") {
		SetNextScene(gamePlayScene);
	}
	else {
		printf("ERROR! NO SUCH SCENE! : %s", sceneName);
	}
}

void SceneFSM::SetNextScene(SceneManager *targetScene) {
	nextScene = targetScene;
	exitCurrentState = true;
}

void SceneFSM::Update(double deltaTime) {
	if (exitCurrentState) {
		currentScene->Exit();

		exitCurrentState = false;
		enterNextState = true;

		currentScene = nextScene;
	}

	if (enterNextState) {
		currentScene->Enter();

		enterNextState = false;
	}

	currentScene->Update(deltaTime);
}

void SceneFSM::Draw() {
	currentScene->Draw();
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
		objectInstance = NULL;
	}
}

SceneFSM::SceneFSM() {

}

SceneFSM::~SceneFSM() {
	delete mainMenuScene;
	delete gamePlayScene;
}