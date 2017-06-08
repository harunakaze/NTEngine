#pragma once
#include "SceneList.h"

class SceneFSM {
public:
	void InitFSM();

	void Draw();
	void Update(double deltaTime);

	void SwitchScene(const char * sceneName);

	//Singleton stuff
	static SceneFSM * getInstance();
	static void destroyInstance();
private:
	SceneFSM();
	~SceneFSM();

	SceneManager *currentScene;
	SceneManager *nextScene;

	bool exitCurrentState = false;
	bool enterNextState = true;

	void SetNextScene(SceneManager *targetScene);

	//Available scene
	MainMenuScene *mainMenuScene;
	GamePlayScene *gamePlayScene;

	//Singleton stuff
	static SceneFSM * objectInstance;
};