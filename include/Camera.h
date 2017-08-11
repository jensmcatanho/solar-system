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
#ifndef CAMERA_H
#define CAMERA_H

#include "Prerequisites.h"

enum Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera {
	public:
		Camera(glm::vec3 position);

		Camera(GLfloat x, GLfloat y, GLfloat z);

		void ProcessKeyboard(Movement direction, GLfloat delta_time);

		void ProcessMouseMovement(GLfloat x_offset, GLfloat y_offset);

		void ProcessMouseScroll(GLfloat y_offset);

		glm::mat4 GetViewMatrix() const;

	private:
		void UpdateVectors();

		glm::vec3 m_Position;

		glm::vec3 m_Front;

		glm::vec3 m_Up;

		glm::vec3 m_Right;

		glm::vec3 m_WorldUp;

		GLfloat m_Yaw;

		GLfloat m_Pitch;

		GLfloat m_MovementSpeed;

		GLfloat m_Sensitivity;

		GLfloat m_Zoom;
};

inline glm::mat4 Camera::GetViewMatrix() const {
	return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

#endif