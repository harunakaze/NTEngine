#include "Global.h"
#include "Camera.h"
#include <math.h>
#include <stdio.h>

GLfloat CAM_SPEED = 2.0f;
GLfloat ROT_SPEED = 1.5f;

Camera::Camera(void)
{
	transValue.x = 0.0f;
	transValue.y = 0.0f;
	transValue.z = 5.0f; //TODO: PERLU OFFSET LAGI PO??? //Cam offset

	rotXValue = 0.0f;
	rotYValue = 0.0f;

	//projectionMatrix.SetPerspective((45.0f*(3.14 / 180.0f)), (float)(Global::screenWidth / Global::screenHeight), 0.1f, 1000.0f);
	projectionMatrix.SetOrthographic((175.0f*(3.14 / 180.0f)), (float)(Global::screenWidth / Global::screenHeight), 0.1f, 1000.0f);

	setWorldMatrix();
	setViewMatrix();

	printf("A Camera Created!\n");
}

Camera::~Camera(void)
{
	printf("A camera has been destroyed !\n");
}

Matrix Camera::getViewMatrix()
{
	return viewMatrix;
}

Matrix Camera::getViewSkyMatrix() //View matrix without translation
{
	Matrix rotX, rotY;

	rotX.SetRotationX(-rotXValue);
	rotY.SetRotationY(-rotYValue);

	return rotY * rotX;
}

Matrix Camera::getWorldMatrix()
{
	return worldMatrix;
}

Matrix Camera::getProjectionMatrix()
{
	return projectionMatrix;
}

Vector3 Camera::getLocation()
{
	return transValue;
}

void Camera::setViewMatrix()
{
	Matrix trans, rotX, rotY;

	trans.SetTranslation(-transValue.x, -transValue.y, -transValue.z);
	rotX.SetRotationX(-rotXValue);
	rotY.SetRotationY(-rotYValue);

	viewMatrix = trans * rotY * rotX;
}

void Camera::setWorldMatrix()
{
	Matrix trans, rotX, rotY;

	trans.SetTranslation(transValue.x, transValue.y, transValue.z);
	rotX.SetRotationX(rotXValue);
	rotY.SetRotationY(rotYValue);

	worldMatrix = rotX * rotY * trans;
}

void Camera::moveForward(float deltaTime)
{
	Vector4 movement = Vector4(0, 0, -deltaTime * CAM_SPEED, 1.0f);
	Vector4 globalMovement = movement * worldMatrix;

	transValue = Vector3(globalMovement.x, globalMovement.y, globalMovement.z);

	setWorldMatrix();
	setViewMatrix();
}

void Camera::moveBackward(float deltaTime)
{
	Vector4 movement = Vector4(0, 0, deltaTime * CAM_SPEED, 1.0f);
	Vector4 globalMovement = movement * worldMatrix;

	transValue = Vector3(globalMovement.x, globalMovement.y, globalMovement.z);

	setWorldMatrix();
	setViewMatrix();
}

void Camera::moveLeft(float deltaTime)
{
	Vector4 movement = Vector4(-deltaTime * CAM_SPEED, 0, 0, 1.0f);
	Vector4 globalMovement = movement * worldMatrix;

	transValue = Vector3(globalMovement.x, globalMovement.y, globalMovement.z);

	setWorldMatrix();
	setViewMatrix();
}

void Camera::moveRight(float deltaTime)
{
	Vector4 movement = Vector4(deltaTime * CAM_SPEED, 0, 0, 1.0f);
	Vector4 globalMovement = movement * worldMatrix;

	transValue = Vector3(globalMovement.x, globalMovement.y, globalMovement.z);

	setWorldMatrix();
	setViewMatrix();
}

void Camera::moveUpward(float deltaTime)
{
	Vector4 movement = Vector4(0, deltaTime * CAM_SPEED, 0, 1.0f);
	Vector4 globalMovement = movement * worldMatrix;

	transValue = Vector3(globalMovement.x, globalMovement.y, globalMovement.z);

	setWorldMatrix();
	setViewMatrix();
}

void Camera::moveDownward(float deltaTime)
{
	Vector4 movement = Vector4(0, -deltaTime * CAM_SPEED, 0, 1.0f);
	Vector4 globalMovement = movement * worldMatrix;

	transValue = Vector3(globalMovement.x, globalMovement.y, globalMovement.z);

	setWorldMatrix();
	setViewMatrix();
}

void Camera::rotateUp(float deltaTime)
{
	rotXValue += deltaTime * ROT_SPEED;

	setWorldMatrix();
	setViewMatrix();
}

void Camera::rotateDown(float deltaTime)
{
	rotXValue -= deltaTime * ROT_SPEED;

	setWorldMatrix();
	setViewMatrix();
}

void Camera::rotateLeft(float deltaTime)
{
	rotYValue += deltaTime * ROT_SPEED;

	setWorldMatrix();
	setViewMatrix();
}

void Camera::rotateRight(float deltaTime)
{
	rotYValue -= deltaTime * ROT_SPEED;

	setWorldMatrix();
	setViewMatrix();
}