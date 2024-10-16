#pragma once

#ifndef V_VERTEXARRAY
#define V_VERTEXARRAY

#include "glad/glad.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
public:
	inline VertexArray()
	{
		glGenVertexArrays(1, &m_ID);
	}

	inline void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const
	{
		Bind();
		vb.Bind();
		layout.Assign();
		Unbind();
	}

	inline void Bind() const
	{
		glBindVertexArray(m_ID);
	}

	inline void Unbind() const
	{
		glBindVertexArray(0);
	}

	inline ~VertexArray()
	{
		glDeleteVertexArrays(1, &m_ID);
	}

private:
	unsigned int m_ID;
};

#endif