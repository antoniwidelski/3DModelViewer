#pragma once

#ifndef V_RENDERER
#define V_RENDERER

#include "glm/glm.hpp"
#include "glad/glad.h"

#include "Shader.h"
#include "Texture.h"

class Renderer
{
public:
	Renderer();

	void Clear() const;

	void SetClearColor(float r, float g, float b) const;
	void SetTexture(const Texture& tex, const Shader& shader);

	bool first = true;
};

#endif