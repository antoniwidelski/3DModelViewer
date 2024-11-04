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

/*void Renderer::Draw(const Model& model, const Shader& shader) const
{
	std::cout << "Size: " << model.m_Meshes.size() << std::endl;
	for (int i = 0; i < model.m_Meshes.size(); i++)
		Draw(model.m_Meshes[i], shader);
}

void Renderer::Draw(const Mesh& mesh, const Shader& shader) const
{
	mesh.m_Texture.Bind();
	Draw(mesh.m_VA, mesh.m_IB, shader);
	std::cout << "Drawuje mesha" << std::endl;
}*/

void Renderer::SetTexture(const Texture& tex, const Shader& shader)
{
	//shader.SetUniformInt("texture_diffuse1", 0);
	tex.Bind();
}