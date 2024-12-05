#include "Renderer.h"

#include <string>

Renderer::Renderer()
{
	glEnable(GL_DEPTH_TEST);
}

void Renderer::SetClearColor(float r, float g, float b) const
{
	glClearColor(r, g, b, 1.0f);
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::SetTexture(const Texture& tex, const Shader& shader)
{
	//shader.SetUniformInt("texture_diffuse1", 0);
	tex.Bind();
}