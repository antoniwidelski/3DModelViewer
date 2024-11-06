#pragma once

#ifndef V_SHADER
#define V_SHADER

#include "glad/glad.h"
#include "glm/glm.hpp"

#include <iostream>

class Shader
{
public:
	Shader(const char* vSource, const char* fSource);
	Shader(const std::string& vPath, const std::string& fPath);

	inline void Use() const { glUseProgram(m_ID); }
	inline unsigned int GetID() const { return m_ID; }

	void SetMat4(const std::string& name, glm::mat4 mat) const;
	void SetVec3(const std::string& name, glm::vec3 vec) const;
	void SetVec3(const std::string& name, float x, float y, float z) const;
	void SetFloat(const std::string& name, float value) const;
	void SetInt(const std::string& name, int value) const;

private:
	unsigned int CreateShader(const char* source, GLenum shaderType);
	unsigned int CreateProgram(unsigned int vShader, unsigned int fShader);
	
	std::string GetErrors(unsigned int object, GLenum statusType);
	std::string LoadFromFile(const std::string& path);

	unsigned int m_ID;
};

#endif