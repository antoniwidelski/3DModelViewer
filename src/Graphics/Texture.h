#pragma once

#include <string>
#include <iostream>

#include "glad/glad.h"
#include "../vendor/stb_image.h"

class Texture
{
public:
	friend class Renderer;
	
	inline Texture(std::string path) : m_Path(path)
	{
		std::cout << "Creating texture..." << std::endl;
		glGenTextures(1, &m_ID);
		glBindTexture(GL_TEXTURE_2D, m_ID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
		unsigned char* data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_NrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			std::cout << "Texture loaded" << std::endl;
		}
		else
		{
			std::cout << "ERROR: Failed to load texture" << std::endl;
		}
		stbi_image_free(data);
	}

	inline void Bind() const
	{
		glBindTexture(GL_TEXTURE_2D, m_ID);
	}

	inline std::string GetPath() const { return m_Path; }
	inline void SetType(const std::string& type) { m_Type = type; }

private:
	unsigned int m_ID;
	int m_Width, m_Height, m_NrChannels;
	std::string m_Path, m_Type;
};