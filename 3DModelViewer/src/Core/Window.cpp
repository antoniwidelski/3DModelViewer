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


Window::Window(int width, int height) : m_Width(width), m_Height(height)
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
	glfwSetWindowUserPointer(m_Window, this);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "ERROR: Failed to initialize GLAD!" << std::endl;
		return;
	}

	glViewport(0, 0, width, height);

	glfwSetKeyCallback(m_Window, KeyCallback);
	glfwSetMouseButtonCallback(m_Window, MouseButtonCallback);
	glfwSetCursorPosCallback(m_Window, CursorPosCallback);

	glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	s_Initialized = true;
}

void Window::SetKeyCallback(const std::function<void(int, int)>& callback)
{
	m_KeyCallback = callback;
}

void Window::SetMouseButtonCallback(const std::function<void(int, int, int)> callback)
{
	m_MouseButtonCallback = callback;
}

void Window::SetCursorPosCallback(const std::function<void(double, double)> callback)
{
	m_CursorPosCallback = callback;
}

void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* win = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

	if (win && win->m_KeyCallback)
	{
		win->m_KeyCallback(key, action);
	}
}

void Window::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	Window* win = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

	if (win && win->m_MouseButtonCallback)
	{
		win->m_MouseButtonCallback(button, action, mods);
	}
}

void Window::CursorPosCallback(GLFWwindow* window, double xPos, double yPos)
{
	Window* win = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

	if (win && win->m_CursorPosCallback)
	{
		win->m_CursorPosCallback(xPos, yPos);
	}
}