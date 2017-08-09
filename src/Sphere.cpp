/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2016 Jean Michel Catanho

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
#include "Sphere.h"

Sphere::Sphere(GLfloat x, GLfloat y, GLfloat z) :
	m_Position(x, y, z) {

}

void Sphere::Start(float radius, unsigned int rings, unsigned int sectors) {
	float R = static_cast<float>(1.0 / (rings - 1));
	float S = static_cast<float>(1.0 / (sectors - 1));

	m_Vertices.resize(rings * sectors * 3);
	m_Normals.resize(rings * sectors * 3);
	m_TexCoords.resize(rings * sectors * 2);
	m_Indices.resize(rings * sectors * 4);

	std::vector<GLfloat>::iterator v_iterator = m_Vertices.begin();
	std::vector<GLfloat>::iterator n_iterator = m_Normals.begin();
	std::vector<GLfloat>::iterator t_iterator = m_TexCoords.begin();
	std::vector<GLushort>::iterator i_iterator = m_Indices.begin();

	for (int i = 0; i < rings; i++) {
		for (int j = 0; j < sectors; j++) {
			float x = glm::cos(2 * PI * j * S) * glm::sin(PI * i * R);
			float y = glm::sin(-HALF_PI + PI * i * R);
			float z = glm::sin(2 * PI * j * S) * glm::sin(PI * i * R);

			*v_iterator++ = x * radius;
			*v_iterator++ = y * radius;
			*v_iterator++ = z * radius;

			*n_iterator++ = x;
			*n_iterator++ = y;
			*n_iterator++ = z;

			*t_iterator++ = j * S;
			*t_iterator++ = i * R;
		}
	}

	for (int i = 0; i < rings - 1; i++) {
		for (int j = 0; j < sectors - 1; j++) {
			*i_iterator++ = i * sectors + j;
			*i_iterator++ = i * sectors + (j + 1);
			*i_iterator++ = (i + 1) * sectors + (j + 1);
			*i_iterator++ = (i + 1) * sectors + j;
		}
	}
}

void Sphere::Draw() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(m_Position.x, m_Position.y, m_Position.z);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &m_Vertices[0]);
	glNormalPointer(GL_FLOAT, 0, &m_Normals[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &m_TexCoords[0]);
	glDrawElements(GL_QUADS, m_Indices.size(), GL_UNSIGNED_SHORT, &m_Indices[0]);
	glPopMatrix();
}