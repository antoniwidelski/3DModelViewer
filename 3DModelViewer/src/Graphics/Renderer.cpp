#include "Renderer.h"

void Renderer::SetClearColor(float r, float g, float b) const
{
	glClearColor(r, g, b, 1.0f);
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Render(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	shader.Use();
	va.Bind();
	ib.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);
}
