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
#include "stb_image/stb_image.h"

Sphere::Sphere(GLfloat x, GLfloat y, GLfloat z, GLfloat radius) :
	m_Position(x, y, z),
	m_Radius(radius) {

}

Sphere::~Sphere() {
	glDeleteProgram(m_ShaderProgram);
	glDeleteTextures(1, &m_DiffuseMap);
	glDeleteTextures(1, &m_SpecularMap);
	glDeleteVertexArrays(1, &m_VAOHandler);
}

void Sphere::Start(unsigned int rings, unsigned int sectors) {
	float R = static_cast<float>(1.0 / (rings - 1));
	float S = static_cast<float>(1.0 / (sectors - 1));

	unsigned int size_vertices = rings * sectors * 3;
	unsigned int size_normals = rings * sectors * 3;
	unsigned int size_texcoords = rings * sectors * 2;

	m_Data.resize(size_vertices + size_normals + size_texcoords);
	m_Indices.resize(rings * sectors * 4);

	std::vector<GLfloat>::iterator d_iterator = m_Data.begin();
	std::vector<GLushort>::iterator i_iterator = m_Indices.begin();

	for (unsigned int i = 0; i < rings; i++) {
		for (unsigned int j = 0; j < sectors; j++) {
			float x = glm::cos(2 * PI * j * S) * glm::sin(PI * i * R);
			float y = glm::sin(-HALF_PI + PI * i * R);
			float z = glm::sin(2 * PI * j * S) * glm::sin(PI * i * R);

			*d_iterator++ = x;
			*d_iterator++ = y;
			*d_iterator++ = z;

			*d_iterator++ = x;
			*d_iterator++ = y;
			*d_iterator++ = z;

			*d_iterator++ = -(j * S);
			*d_iterator++ = i * R;
		}
	}

	for (unsigned int i = 0; i < rings - 1; i++) {
		for (unsigned int j = 0; j < sectors - 1; j++) {
			*i_iterator++ = (i + 1) * sectors + j;
			*i_iterator++ = (i + 1) * sectors + (j + 1);
			*i_iterator++ = i * sectors + (j + 1);
			*i_iterator++ = i * sectors + j;
		}
	}
}

void Sphere::Load(const GLchar *vertex, const GLchar *frag, const GLchar *diffuse_map, const GLchar *specular_map) {
	GLuint vbo;
	GLuint ebo;

	glGenVertexArrays(1, &m_VAOHandler);
	glBindVertexArray(m_VAOHandler);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, m_Data.size() * sizeof(GLfloat), &m_Data.front(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void *)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void *)(6 * sizeof(GLfloat)));

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(GLushort), &m_Indices.front(), GL_STATIC_DRAW);

	LoadShaders(vertex, frag);
	
	m_DiffuseMap = LoadTexture(diffuse_map);
	m_SpecularMap = LoadTexture(specular_map);

	glBindVertexArray(0);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
	
	m_Data.clear();
	m_Data.shrink_to_fit();
}

void Sphere::LoadShaders(const GLchar *vertex, const GLchar *frag) {
	GLint status;

	std::string vertex_source = Core::ReadFile(vertex).str();
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

	std::string fragment_source = Core::ReadFile(frag).str();
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

	glBindAttribLocation(m_ShaderProgram, 0, "a_Position");
	glBindAttribLocation(m_ShaderProgram, 1, "a_Normal");
	glBindAttribLocation(m_ShaderProgram, 2, "a_TexCoord");

	glLinkProgram(m_ShaderProgram);
	glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &status);

	if (!status) {
		char error_log[512];

		glGetProgramInfoLog(m_ShaderProgram, 512, NULL, error_log);
		std::cout << "========== Shader linking log ==========" << std::endl;
		std::cout << error_log << std::endl;

		return;
	}

	glDetachShader(m_ShaderProgram, vertex_shader);
	glDeleteShader(vertex_shader);

	glDetachShader(m_ShaderProgram, fragment_shader);
	glDeleteShader(fragment_shader);
}

GLuint Sphere::LoadTexture(const GLchar *texture_path) {
	GLint width;
	GLint height;
	GLint num_channels;

	GLuint texture_handler;

	stbi_set_flip_vertically_on_load(true);

	unsigned char *data = stbi_load(texture_path, &width, &height, &num_channels, 0);

	if (data) {
		glGenTextures(1, &texture_handler);
		glBindTexture(GL_TEXTURE_2D, texture_handler);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	
	} else {
		std::cout << "Failed to load the texture." << std::endl;
	}

	stbi_image_free(data);

	return texture_handler;
}