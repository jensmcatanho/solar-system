/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2017 Jean Michel Catanho

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
-----------------------------------------------------------------------------
*/
#include "Camera.h"

Camera::Camera(glm::vec3 position) :
	m_Position(position),
	m_WorldUp(0.0f, 1.0f, 0.0f),
	m_Yaw(YAW),
	m_Pitch(PITCH), 
	m_MovementSpeed(SPEED),
	m_Sensitivity(SENSITIVITY),
	m_Zoom(ZOOM) {

	UpdateVectors();
}

Camera::Camera(GLfloat x, GLfloat y, GLfloat z) :
	m_Position(x, y, z),
	m_WorldUp(0.0f, 1.0f, 0.0f),
	m_Yaw(YAW),
	m_Pitch(PITCH), 
	m_MovementSpeed(SPEED),
	m_Sensitivity(SENSITIVITY),
	m_Zoom(ZOOM) {

	UpdateVectors();
}

void Camera::ProcessKeyboard(Movement direction, GLfloat delta_time) {
	GLfloat velocity = m_MovementSpeed * delta_time;

	if (direction == FORWARD)
		m_Position += m_Front * velocity;
	else if (direction == BACKWARD)
		m_Position -= m_Front * velocity;
	else if (direction == LEFT)
		m_Position -= m_Right * velocity;
	else
		m_Position += m_Right * velocity;
}

void Camera::ProcessMouseMovement(GLfloat x_offset, GLfloat y_offset) {
	m_Yaw += x_offset * m_Sensitivity;
	m_Pitch += y_offset * m_Sensitivity;

	if (m_Pitch > 89.9f)
		m_Pitch = 89.9f;
	if (m_Pitch < -89.9f)
		m_Pitch = -89.9f;

	UpdateVectors();
}

void Camera::ProcessMouseScroll(GLfloat y_offset) {
	if (m_Zoom >= 1.0f && m_Zoom <= 45.0f)
		m_Zoom -= y_offset;

	if (m_Zoom <= 1.0f)
		m_Zoom = 1.0f;
	if (m_Zoom >= 45.0f)
		m_Zoom = 45.0f;
}

void Camera::UpdateVectors() {
	glm::vec3 front;
	front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	front.y = sin(glm::radians(m_Pitch));
	front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

	m_Front = glm::normalize(front);
	m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
	m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}