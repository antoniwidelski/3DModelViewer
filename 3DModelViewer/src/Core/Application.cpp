#include "Application.h"

#include <iostream>

#include "Common.h"
#include "../Graphics/Shader.h"
#include "../Graphics/VertexBuffer.h"
#include "../Graphics/VertexBufferLayout.h"
#include "../Graphics/VertexArray.h"
#include "../Graphics/IndexBuffer.h"
#include "../Graphics/Renderer.h"

Application::Application()
{
	m_Window = Window::CreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void Application::Run()
{
	Shader shader(vSource, fSource);

	VertexBuffer vb(&vertices[0], 9 * sizeof(float));
	VertexBufferLayout layout;
	layout.AddAttribute(3, 3, 0);
	VertexArray va;
	va.AddBuffer(vb, layout);

	IndexBuffer ib(&indices[0], 3);

	Renderer renderer;

	// loop
	while (!m_Window->GetShouldClose())
	{
		renderer.SetClearColor(0.8f, 0.2f, 0.5f);
		renderer.Clear();
		renderer.Render(va, ib, shader);

		m_Window->Update(1.0f);
	}
}

void Application::Shutdown()
{
	delete m_Window;
}