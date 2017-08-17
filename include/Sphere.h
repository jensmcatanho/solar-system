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
#ifndef SPHERE_H
#define SPHERE_H

#include "Prerequisites.h"

class Sphere {
	public:
		Sphere(GLfloat x, GLfloat y, GLfloat z, GLfloat radius);

		~Sphere();

		void Start(unsigned int rings, unsigned int sectors);

		void Load(const GLchar *vertex, const GLchar *frag, const GLchar *diffuse_map, const GLchar *specular_map);

		virtual void Draw(glm::mat4 vp_matrix) = 0;

		glm::vec3 m_Position;

	protected:
		std::vector<GLushort> m_Indices;

		GLfloat m_Radius;

		GLuint m_ShaderProgram;

		GLuint m_VAOHandler;

		GLuint m_DiffuseMap;

		GLuint m_SpecularMap;

	private:
		void LoadShaders(const GLchar *vertex, const GLchar *frag);

		GLuint LoadTexture(const GLchar *texture_path);

		std::vector<GLfloat> m_Data;
};

#endif