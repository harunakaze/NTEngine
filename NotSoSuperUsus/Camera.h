#pragma once
#include "../Utilities/utilities.h"

class Camera
{
public:
	Camera(void);
	~Camera(void);

	Matrix getViewMatrix();
	Matrix getViewSkyMatrix();
	Matrix getWorldMatrix();
	Matrix getProjectionMatrix();
	Vector3 getLocation();

	void moveForward(float deltaTime);
	void moveBackward(float deltaTime);
	void moveLeft(float deltaTime);
	void moveRight(float deltaTime);
	void moveUpward(float deltaTime);
	void moveDownward(float deltaTime);

	void rotateUp(float deltaTime);
	void rotateDown(float deltaTime);
	void rotateLeft(float deltaTime);
	void rotateRight(float deltaTime);

private:
	Matrix worldMatrix;
	Matrix viewMatrix;
	Matrix projectionMatrix;

	Vector3 transValue; //Ini posisi dia
	float rotXValue, rotYValue;

	void setWorldMatrix();
	void setViewMatrix();
};
