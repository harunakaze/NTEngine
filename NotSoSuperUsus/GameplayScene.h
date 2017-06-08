#pragma once
#include "SceneManager.h"

class GamePlayScene : public SceneManager {
public:
	void Init();
	void Update(double deltaTime);
};