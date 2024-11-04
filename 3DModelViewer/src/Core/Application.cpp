#include "Application.h"

#include <iostream>
#include <functional>
#include <memory>

#include "Common.h"
#include "../Graphics/Shader.h"
#include "../Graphics/Renderer.h"
#include "../Graphics/Model.h"

#include "../vendor/stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Application::Application()
{
	for (int i = 0; i < 1024; i++)
	{
		m_Keys[i] = false;
	}

	m_Window = Window::CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
	if (m_Window)
	{
		m_Window->SetKeyCallback(std::bind(&Application::OnKeyEvent, this, std::placeholders::_1, std::placeholders::_2));
		m_Window->SetMouseButtonCallback(std::bind(&Application::OnMouseButtonEvent, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		m_Window->SetCursorPosCallback(std::bind(&Application::OnCursorPosEvent, this, std::placeholders::_1, std::placeholders::_2));
	}

	stbi_set_flip_vertically_on_load(true);
}

Application::~Application()
{
	Shutdown();
}

void Application::Run()
{
	deltaTime = 0.0f;
	float lastFrame = 0.0f;

	std::string vPath = "res/shader.vs";
	std::string fPath = "res/shader.fs";
	Shader shader(vPath, fPath);	

	Model _model((char*)"res/backpack/backpack.obj");

	shader.Use();
	glm::mat4 projection = glm::perspective(m_Camera.GetFOV(), m_Window->GetAspect(), 0.1f, 100.0f);
	shader.SetUniformMat4("projection", projection);

	Renderer renderer;

	// loop
	while (!m_Window->GetShouldClose())
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		renderer.SetClearColor(0.8f, 0.2f, 0.5f);
		renderer.Clear();

		glm::mat4 model(1.0f);

		shader.SetUniformMat4("model", model);

		m_Camera.ManageKeyInput(m_Keys, deltaTime);

		shader.SetUniformMat4("view", m_Camera.GetViewMatrix());

		_model.Draw(shader);

		m_Window->Update(deltaTime);
	}
}

void Application::Shutdown()
{
	delete m_Window;
}

void Application::OnMouseButtonEvent(int button, int action, int mods)
{
	std::cout << "Button: " << button << ", Action: " << action << std::endl;
}

void Application::OnCursorPosEvent(double xpos, double ypos)
{
	std::cout << "MousePos: X: " << xpos << ", Y: " << ypos << std::endl;

	m_Camera.ManageCursorPos(xpos, ypos);
}

void Application::OnKeyEvent(int key, int action)
{
	if (action == GLFW_PRESS)
	{
		m_Keys[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		m_Keys[key] = false;
	}

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		m_Window->SetShouldClose(true);
	}
}