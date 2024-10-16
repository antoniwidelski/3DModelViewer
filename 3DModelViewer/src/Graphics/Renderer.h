#pragma once

#ifndef V_RENDERER
#define V_RENDERER

#include "glm/glm.hpp"
#include "glad/glad.h"

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
	void SetClearColor(float r, float g, float b) const;
	void Clear() const;
	void Render(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};

#endif