#pragma once

#ifndef V_VERTEXBUFFER
#define V_VERTEXBUFFER

#include "glad/glad.h"

class VertexBuffer
{
public:
	inline VertexBuffer(float* data, unsigned int size)
		: m_Size(size)
	{
		glGenBuffers(1, &m_ID);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), data, GL_STATIC_DRAW);
	}

	inline void Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}

	inline void Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	inline ~VertexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

private:
	unsigned int m_ID;
	unsigned int m_Size;
};

#endif