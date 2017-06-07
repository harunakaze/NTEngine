//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

//Include the standard C++ headers
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Include object header
#include "Camera.h"
#include "Global.h"
#include "Shaders.h"
#include "Vertex.h"
#include "SceneFSM.h"
#include "ResourceManager.h"

//Define an error callback
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
	_fgetchar();
}

//Define the key input callback
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


void Init()
{
	//Set a background color
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	
	//GL Feature
	//glEnable(GL_DEPTH_TEST);
	//glEnable(GL_BLEND); 
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Init RM & SM
	ResourceManager::getInstance()->Init();
	SceneFSM::getInstance()->InitFSM();
}

void Update(double deltaTime) {
	// Scene manager update
	SceneFSM::getInstance()->Update(deltaTime);
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Scene manager draw
	SceneFSM::getInstance()->Draw();
}

void CleanUp()
{
	Camera::destroyInstance();
	ResourceManager::destroyInstance();
}

int main(void)
{
	//Set the error callback
	glfwSetErrorCallback(error_callback);

	//Initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}

	//Set the GLFW window creation hints - these are optional
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Request a specific OpenGL version
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Request a specific OpenGL version
	//glfwWindowHint(GLFW_SAMPLES, 4); //Request 4x antialiasing
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Declare a window object
	GLFWwindow* window;

	//Create a window and create its OpenGL context
	window = glfwCreateWindow(Global::screenWidth, Global::screenHeight, "Not So Super Usus", NULL, NULL);

	//If the window couldn't be created
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//This function makes the context of the specified window current on the calling thread. 
	glfwMakeContextCurrent(window);

	//Sets the key callback
	glfwSetKeyCallback(window, key_callback);

	//Initialize GLEW
	GLenum err = glewInit();

	//If GLEW hasn't initialized
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		return -1;
	}

	//Inital preparation
	Init();

	double lastTime = glfwGetTime();
	
	//Main Loop
	do
	{
		double curTime = glfwGetTime();
		double deltaTime = (curTime - lastTime);
		lastTime = curTime;

		//Update Loop
		//TODO: USE FIXED TIME STEP
		Update(deltaTime);

		//Draw loop
		Draw();

		//Swap buffers
		glfwSwapBuffers(window);
		//Get and organize events, like keyboard and mouse input, window resizing, etc...
		glfwPollEvents();

	} //Check if the ESC key had been pressed or if the window had been closed
	while (!glfwWindowShouldClose(window));

	//Release Resources
	CleanUp();

	//Close OpenGL window and terminate GLFW
	glfwDestroyWindow(window);
	//Finalize and clean up GLFW
	glfwTerminate();

	printf("Press any key...\n");
	_getch();

	exit(EXIT_SUCCESS);
}