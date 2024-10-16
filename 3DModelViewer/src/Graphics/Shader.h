#pragma once

#ifndef V_SHADER
#define V_SHADER

#include "glad/glad.h"

#include <iostream>

class Shader
{
public:
	Shader(const char* vSource, const char* fSource);

	inline void Use() const { glUseProgram(m_ID); }
	inline unsigned int GetID() const { return m_ID; }

private:
	unsigned int CreateShader(const char* source, GLenum shaderType);
	unsigned int CreateProgram(unsigned int vShader, unsigned int fShader);
	std::string GetErrors(unsigned int object, GLenum statusType);
	
	unsigned int m_ID;
};

#endif