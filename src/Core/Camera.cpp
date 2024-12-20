#include "Camera.h"

#include "GLFW/glfw3.h"
#include <iostream>

Camera::Camera() :
	m_Pos(0.0f, 0.0f, 3.0f),
	m_Front(0.0f, 0.0f, -1.0f),
	m_Up(0.0f, 1.0f, 0.0f),
	m_FirstMouse(true),
	m_Yaw(-90.0f),
	m_Pitch(0.0f),
	m_FOV(45.0f),
	m_Speed(2.5f)
{
	m_LastX = 400.0f;
	m_LastY = 300.0f;
}

void Camera::ManageCursorPos(double xPos, double yPos)
{
	if (m_FirstMouse)
	{
		m_LastX = xPos;
		m_LastY = yPos;
		m_FirstMouse = false;
		std::cout << "first mouse" << std::endl;
	}

	float xOffset = xPos - m_LastX;
	float yOffset = m_LastY - yPos;
	m_LastX = xPos;
	m_LastY = yPos;

	const float sensitivity = 0.1;
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	m_Yaw += xOffset;
	m_Pitch += yOffset;

	if (m_Pitch > 89.0f)
		m_Pitch = 89.0f;
	if (m_Pitch < -89.0f)
		m_Pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	front.y = sin(glm::radians(m_Pitch));
	front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Front = glm::normalize(front);
}

void Camera::ManageKeyInput(bool* keys, double deltaTime)
{
	float speed = m_Speed * deltaTime;
	if (keys[GLFW_KEY_W])
		m_Pos += speed * m_Front;
	if (keys[GLFW_KEY_S])
		m_Pos -= speed * m_Front;
	if (keys[GLFW_KEY_A])
		m_Pos -= glm::normalize(glm::cross(m_Front, m_Up)) * speed;
	if (keys[GLFW_KEY_D])
		m_Pos += glm::normalize(glm::cross(m_Front, m_Up)) * speed;
}
