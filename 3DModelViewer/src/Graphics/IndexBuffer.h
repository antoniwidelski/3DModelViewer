#pragma once

#ifndef V_INDEXBUFFER
#define V_INDEXBUFFER

#include "glad/glad.h"

class IndexBuffer
{
public:
	inline IndexBuffer(unsigned int* data, unsigned int count)
		: m_Count(count)
	{
		glGenBuffers(1, &m_ID);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
	}

	inline void Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}

	inline void Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	inline unsigned int GetCount() const
	{
		return m_Count;
	}

	inline ~IndexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

private:
	unsigned int m_ID;
	unsigned int m_Count;
};

#endif