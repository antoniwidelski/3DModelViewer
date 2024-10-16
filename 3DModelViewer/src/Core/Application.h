#pragma once

#ifndef V_APPLICATION
#define V_APPLICATION

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <assimp/Importer.hpp>
#include "Window.h"

class Application
{
public:
	Application();
	void Run();
	void Shutdown();
	
private:
	Window* m_Window;
};

#endif