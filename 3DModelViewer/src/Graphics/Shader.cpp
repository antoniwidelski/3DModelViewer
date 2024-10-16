#include "Shader.h"

Shader::Shader(const char* vSource, const char* fSource)
{
	unsigned int vShader = CreateShader(vSource, GL_VERTEX_SHADER);
	unsigned int fShader = CreateShader(fSource, GL_FRAGMENT_SHADER);

	m_ID = CreateProgram(vShader, fShader);

	glDeleteShader(vShader);
	glDeleteShader(fShader);
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
		std::cout << "ERROR::SHADER::" << type << "COMPILATION_FAILED\n" << infoLog << std::endl;
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