#pragma once

#ifndef V_WINDOW
#define V_WINDOW

#include <glad/glad.h>
#include <glfw/glfw3.h>

class Window
{
public:
	static Window* CreateWindow(int width, int height);
	~Window();
	void Update(double deltaTime);

	inline bool GetShouldClose() { return glfwWindowShouldClose(m_Window); }
	inline GLFWwindow* GetWindow() const { return m_Window; }

private:
	Window(int width, int height);

	GLFWwindow* m_Window;
	bool m_ShouldClose;
};

#endif