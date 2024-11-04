#pragma once

#ifndef V_WINDOW
#define V_WINDOW

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <functional>

class Window
{
public:
	static Window* CreateWindow(int width, int height);
	~Window();
	void Update(double deltaTime);

	inline void SetShouldClose(bool b) { glfwSetWindowShouldClose(m_Window, b); }
	inline bool GetShouldClose() { return glfwWindowShouldClose(m_Window); }
	inline GLFWwindow* GetWindow() const { return m_Window; }
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline void GetCursorPos(double* xPos, double* yPos) const { glfwGetCursorPos(m_Window, xPos, yPos); }
	float GetAspect() const { return static_cast<float>(m_Width) / static_cast<float>(m_Height); }

	void SetKeyCallback(const std::function<void(int, int)>& callback);
	void SetMouseButtonCallback(const std::function<void(int, int, int)> callback);
	void SetCursorPosCallback(const std::function<void(double, double)> callback);

private:
	Window(int width, int height);
	
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void CursorPosCallback(GLFWwindow* window, double xPos, double yPos);



	int m_Width, m_Height;
	GLFWwindow* m_Window;
	bool m_ShouldClose;

	std::function<void(int, int)> m_KeyCallback;
	std::function<void(int, int, int)> m_MouseButtonCallback;
	std::function<void(double, double)> m_CursorPosCallback;
};

#endif