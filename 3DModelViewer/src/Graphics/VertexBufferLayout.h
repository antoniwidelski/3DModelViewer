#pragma once

#ifndef V_VERTEXARRAYLAYOUT
#define V_VERTEXARRAYLAYOUT

#include "glad/glad.h"

#include <vector>

struct attribute
{
	unsigned int size, stride, offset;
};

class VertexBufferLayout
{
public:
	inline void AddAttribute(unsigned int size, unsigned int stride, unsigned int offset)
	{
		attribute attrib = { size, stride, offset };
		attribs.push_back(attrib);
	}

	inline void Assign() const
	{
		for (int i = 0; i < attribs.size(); i++)
		{
			glVertexAttribPointer(i, attribs[i].size, GL_FLOAT, GL_FALSE, attribs[i].stride * sizeof(float), (void*)attribs[i].offset);
			glEnableVertexAttribArray(i);
		}
	}

private:
	std::vector<attribute> attribs;
};

#endif