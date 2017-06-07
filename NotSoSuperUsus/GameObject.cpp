#include "GameObject.h"
#include "SceneManager.h"
#include "Camera.h"
#include <stdio.h>

void GameObject::Update(double deltaTime) {
	//printf("%f\n", deltaTime);
}

void GameObject::Draw() {
	glUseProgram(shaders->program);

	glBindBuffer(GL_ARRAY_BUFFER, model->vboId);

	// Enable attribute
	if (shaders->positionAttribute != -1)
	{
		glEnableVertexAttribArray(shaders->positionAttribute);
		glVertexAttribPointer(shaders->positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vector2) * 1));
	}

	if (shaders->uvAttribute != -1)
	{
		glEnableVertexAttribArray(shaders->uvAttribute);
		glVertexAttribPointer(shaders->uvAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	}

	// Bind texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->idTexture);
	glUniform1i(shaders->texture, 0);

	MVP = modelMatrix * Camera::mainCamera()->getViewMatrix() * Camera::mainCamera()->getProjectionMatrix();

	if (shaders->transformationMatrix != -1)
	{
		glUniformMatrix4fv(shaders->transformationMatrix, 1, GL_FALSE, &MVP.m[0][0]);
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->iboId);

	glDrawElements(GL_TRIANGLES, model->indicesCount, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void GameObject::UpdateWorldMatrix()
{
	Matrix transMat, scaleMat, rotXMat, rotYMat, rotZMat;

	transMat.SetTranslation(position.x, position.y, position.z);
	scaleMat.SetScale(scale.x, scale.y, scale.z);

	rotXMat.SetRotationX(rotation.x);
	rotYMat.SetRotationY(rotation.y);
	rotZMat.SetRotationZ(rotation.z);

	modelMatrix = scaleMat * rotZMat * rotXMat * rotYMat * transMat;
}

GameObject::GameObject() {

}

GameObject::~GameObject() {

}