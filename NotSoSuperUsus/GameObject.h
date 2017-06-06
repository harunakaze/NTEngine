#pragma once
#include "../Utilities/utilities.h"
#include "Model.h"
#include "Texture.h"
#include "Shaders.h"

class GameObject {
public:
	GameObject();
	~GameObject();

	//Transform properties
	Vector3 position;
	Vector3 scale;
	Vector3 rotation;
	Matrix modelMatrix;
	Matrix MVP;
	void UpdateWorldMatrix(); //Set World Matrix

	//Main Function
	void Draw();
	void Update(double deltaTime);

	//Model
	Model * model;

	//2D Texture
	Texture * texture;

	//Shaders
	Shaders * shaders;
};