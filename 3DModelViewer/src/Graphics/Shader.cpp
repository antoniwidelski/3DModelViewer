#include "Shader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "glm/gtc/type_ptr.hpp"

Shader::Shader(const char* vSource, const char* fSource)
{
	unsigned int vShader = CreateShader(vSource, GL_VERTEX_SHADER);
	unsigned int fShader = CreateShader(fSource, GL_FRAGMENT_SHADER);

	m_ID = CreateProgram(vShader, fShader);

	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

Shader::Shader(const std::string& vPath, const std::string& fPath)
{
	std::string vStr = LoadFromFile(vPath);
	std::string fStr = LoadFromFile(fPath);

	const char* vSource = vStr.c_str();
	const char* fSource = fStr.c_str();

	unsigned int vShader = CreateShader(vSource, GL_VERTEX_SHADER);
	unsigned int fShader = CreateShader(fSource, GL_FRAGMENT_SHADER);

	m_ID = CreateProgram(vShader, fShader);

	glDeleteShader(vShader);
	glDeleteShader(fShader);
}

std::string Shader::LoadFromFile(const std::string& path)
{
	std::ifstream file(path);
	std::stringstream ss;

	ss << file.rdbuf();

	file.close();
	return ss.str();
}

void Shader::SetMat4(const std::string& name, glm::mat4 mat) const
{
	unsigned int loc = glGetUniformLocation(m_ID, name.c_str());
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetVec3(const std::string& name, glm::vec3 vec) const
{
	unsigned int loc = glGetUniformLocation(m_ID, name.c_str());
	glUniform3f(loc, vec.x, vec.y, vec.z);
}

void Shader::SetVec3(const std::string& name, float x, float y, float z) const
{
	unsigned int loc = glGetUniformLocation(m_ID, name.c_str());
	glUniform3f(loc, x, y, z);
}

void Shader::SetFloat(const std::string& name, float value) const
{
	unsigned int loc = glGetUniformLocation(m_ID, name.c_str());
	glUniform1f(loc, value);
}

void Shader::SetInt(const std::string& name, int value) const
{
	unsigned int loc = glGetUniformLocation(m_ID, name.c_str());
	glUniform1i(loc, value);
}

unsigned int Shader::CreateShader(const char* source, GLenum shaderType)
{
	unsigned int shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	std::string infoLog = GetErrors(shader, GL_COMPILE_STATUS);
	if (infoLog != "")
	{
		std::string type = (shaderType == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT";
		std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	return shader;
}

unsigned int Shader::CreateProgram(unsigned int vShader, unsigned int fShader)
{
	unsigned int program = glCreateProgram();
	glAttachShader(program, vShader);
	glAttachShader(program, fShader);
	glLinkProgram(program);

	std::string infoLog = GetErrors(program, GL_LINK_STATUS);
	if (infoLog != "")
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;

	return program;
}

std::string Shader::GetErrors(unsigned int object, GLenum statusType)
{
	int success;
	char infoLog[512];

	switch (statusType)
	{
	case GL_COMPILE_STATUS:
		glGetShaderiv(object, statusType, &success);
	case GL_LINK_STATUS:
		glGetProgramiv(object, statusType, &success);
	}
	if (!success)
	{
		switch (statusType)
		{
		case GL_COMPILE_STATUS:
			glGetShaderInfoLog(object, 512, NULL, infoLog);
		case GL_LINK_STATUS:
			glGetProgramInfoLog(object, 512, NULL, infoLog);
		}

		return infoLog;
	}
	else
		return "";
}