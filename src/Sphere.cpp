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
#include "Core.h"

Sphere::Sphere(GLfloat x, GLfloat y, GLfloat z) :
	m_Position(x, y, z) {

}

Sphere::~Sphere() {
	glDeleteProgram(m_ShaderProgram);
	glDeleteVertexArrays(1, &m_VAO);
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

void Sphere::Load() {
	GLuint vbos[3];
	GLuint ebo;

	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(3, vbos);

	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(GLfloat), &m_Vertices.front(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
	glBufferData(GL_ARRAY_BUFFER, m_Normals.size() * sizeof(GLfloat), &m_Normals.front(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbos[2]);
	glBufferData(GL_ARRAY_BUFFER, m_TexCoords.size() * sizeof(GLfloat), &m_TexCoords.front(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(GLushort), &m_Indices.front(), GL_STATIC_DRAW);

	LoadShaders();

	glBindVertexArray(0);
	glDeleteBuffers(3, vbos);
	glDeleteBuffers(1, &ebo);
}

void Sphere::LoadShaders() {
	GLint status;

	std::string vertex_source = Core::ReadFile("resources/vertex.glsl").str();
	const GLchar *vertex_code = const_cast<const GLchar *>(vertex_source.c_str());

	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_code, NULL);
	glCompileShader(vertex_shader);
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &status);

	if (!status) {
		char error_log[512];

		glGetShaderInfoLog(vertex_shader, 512, NULL, error_log);
		std::cout << "========== Vertex shader log ==========" << std::endl;
		std::cout << error_log << std::endl;

		return;
	}

	std::string fragment_source = Core::ReadFile("resources/fragment.glsl").str();
	const GLchar *fragment_code = const_cast<const GLchar *>(fragment_source.c_str());

	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_code, NULL);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &status);

	if (!status) {
		char error_log[512];

		glGetShaderInfoLog(fragment_shader, 512, NULL, error_log);
		std::cout << "========== Fragment shader log ==========" << std::endl;
		std::cout << error_log << std::endl;

		return;
	}

	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, vertex_shader);
	glAttachShader(m_ShaderProgram, fragment_shader);

	glBindAttribLocation(m_ShaderProgram, 0, "in_Position");
	glBindAttribLocation(m_ShaderProgram, 1, "in_Normal");
	glBindAttribLocation(m_ShaderProgram, 2, "in_TexCoord");

	glLinkProgram(m_ShaderProgram);
	glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &status);

	if (!status) {
		char error_log[512];

		glGetProgramInfoLog(m_ShaderProgram, 512, NULL, error_log);
		std::cout << "========== Shader linking log ==========" << std::endl;
		std::cout << error_log << std::endl;

		return;
	}

	m_MVPLocation = glGetUniformLocation(m_ShaderProgram, "un_mvpMatrix");

	glDetachShader(m_ShaderProgram, vertex_shader);
	glDeleteShader(vertex_shader);

	glDetachShader(m_ShaderProgram, fragment_shader);
	glDeleteShader(fragment_shader);
}

void Sphere::Draw(glm::mat4 vp_matrix) {
	glBindVertexArray(m_VAO);
	glUseProgram(m_ShaderProgram);

	glm::mat4 translate = glm::translate(glm::mat4(1.0), m_Position);
	glm::mat4 scale;
	glm::mat4 rotation;
	glm::mat4 mvp_matrix = vp_matrix * translate * rotation * scale;
	glUniformMatrix4fv(m_MVPLocation, 1, GL_FALSE, glm::value_ptr(mvp_matrix));

	glDrawElements(GL_QUADS, m_Indices.size(), GL_UNSIGNED_SHORT, (void *)0);

	glBindVertexArray(0);
	glUseProgram(0);
}