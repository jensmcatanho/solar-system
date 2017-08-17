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
#include "Star.h"

Star::Star(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLfloat rotation_period, GLfloat axial_tilt) :
	Sphere(x, y, z, radius),
	m_RotationPeriod(rotation_period),
	m_AxialTilt(axial_tilt) {

}

void Star::Draw(glm::mat4 vp_matrix) {
	glBindVertexArray(m_VAOHandler);
	glUseProgram(m_ShaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_DiffuseMap);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_SpecularMap);

	glm::mat4 model;
	model = glm::translate(model, m_Position);
	model = glm::rotate(model, glm::radians(m_AxialTilt), glm::vec3(0.0, 0.0, 1.0));
	model = glm::rotate(model, glm::radians(45.0f) * (float)glfwGetTime(), glm::vec3(0.0, 1.0, 0.0));
	model = glm::scale(model, glm::vec3(m_Radius, m_Radius, m_Radius));
	glm::mat4 mvp_matrix = vp_matrix * model;

	// Vertex Shader
	glUniformMatrix4fv(3, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(4, 1, GL_FALSE, glm::value_ptr(mvp_matrix));

	// Fragment Shader
	glUniform1i(5, 0);
	glUniform1i(6, 1);

	glDrawElements(GL_QUADS, m_Indices.size(), GL_UNSIGNED_SHORT, (void *)0);
}