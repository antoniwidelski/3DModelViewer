#pragma once

#ifndef V_APPLICATION
#define V_APPLICATION

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <assimp/Importer.hpp>

#include "Window.h"
#include "Camera.h"

#include "glm/glm.hpp"
#include <vector>

class Application
{
public:
	Application();
	~Application();

	void Run();

	
private:
	Window* m_Window;
	Camera m_Camera;

	void Shutdown();

	void OnKeyEvent(int key, int action);
	void OnMouseButtonEvent(int button, int action, int mods);
	void OnCursorPosEvent(double xpos, double ypos);

	float deltaTime;

	bool m_Keys[1024];
};

#endif