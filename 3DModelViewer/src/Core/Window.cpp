#include "Window.h"

#include <iostream>

static bool s_Initialized = false;

Window* Window::CreateWindow(int width, int height)
{
	if (!s_Initialized)
	{
		Window* newWindow = new Window(width, height);
		if (!s_Initialized)
		{
			std::cout << "ERROR: Failed to create window." << std::endl;
			return nullptr;
		}
		return newWindow;
	}
	else
	{
		std::cout << "ERROR: Failed to create window. Window already exists!" << std::endl;
		return nullptr;
	}
}

Window::~Window()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();
	s_Initialized = false;
}

void Window::Update(double deltaTime)
{
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}


Window::Window(int width, int height)
{
	if (glfwInit() == 0)
	{
		std::cout << "ERROR: Failed to initialize GLFW!" << std::endl;
		return;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	m_Window = glfwCreateWindow(width, height, "3DModelViewer", NULL, NULL);
	if (m_Window == NULL)
	{
		std::cout << "ERROR: Failed to create GLFW window!" << std::endl;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(m_Window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "ERROR: Failed to initialize GLAD!" << std::endl;
		return;
	}

	glViewport(0, 0, width, height);



	s_Initialized = true;
}