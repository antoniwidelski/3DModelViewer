#pragma once

#include "glm/glm.hpp"
#include "Shader.h"

class Light
{
public:
	inline Light(glm::vec3 dir, glm::vec3 amb, glm::vec3 diff, glm::vec3 spec)
		: m_Direction(dir), m_Ambient(amb), m_Diffuse(diff), m_Specular(spec) 
	{
	}

	inline void Update(Shader& shader, glm::vec3 cameraPosition)
	{
		shader.SetVec3("light.direction", m_Direction);
		shader.SetVec3("viewPos", cameraPosition);

		shader.SetVec3("light.ambient", m_Ambient);
		shader.SetVec3("light.diffuse", m_Diffuse);
		shader.SetVec3("light.specular", m_Specular);
	}

	inline glm::vec3 GetDirection() const { return m_Direction; }
	inline glm::vec3 GetAmbient() const { return m_Ambient; }
	inline glm::vec3 GetDiffuse() const { return m_Diffuse; }
	inline glm::vec3 GetSpecular() const { return m_Specular; }

private:
	glm::vec3 m_Direction;

	glm::vec3 m_Ambient;
	glm::vec3 m_Diffuse;
	glm::vec3 m_Specular;
};