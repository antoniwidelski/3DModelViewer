#pragma once

#ifndef V_CAMERA
#define V_CAMERA

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera
{
public:
	Camera();

	inline glm::vec3 GetPosition() const { return m_Pos; }
	inline glm::mat4 GetViewMatrix() const { return glm::lookAt(m_Pos, m_Pos + m_Front, m_Up); }
	inline float GetFOV() const { return m_FOV; }

	void ManageCursorPos(double xPos, double yPos);
	void ManageKeyInput(bool* keys, double deltaTime);
	
private:
	glm::vec3 m_Pos;
	glm::vec3 m_Front;
	glm::vec3 m_Up;
	float m_Speed;

	bool m_FirstMouse;
	float m_Yaw;
	float m_Pitch;
	double m_LastX;
	double m_LastY;
	float m_FOV;
};

#endif