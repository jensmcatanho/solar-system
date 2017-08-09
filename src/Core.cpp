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
#include "Core.h"
#include "Window.h"
#include "Sphere.h"

Core::Core() :
	m_Window(new Window(1024, 768)),
	m_SolarSystem(new SolarSystem(1)) {

}

void Core::Setup() {
	m_Window->Create("Solar System");

	// GLEW initialization
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW." << std::endl;
	}

	m_SolarSystem->Start();
}

void Core::Run() {
	while (!glfwWindowShouldClose(m_Window->GetPointer())) {
		float aspect_ratio = (float)m_Window->m_Width / (float)m_Window->m_Height;
		glViewport(0, 0, m_Window->m_Width, m_Window->m_Height);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45, aspect_ratio, 1, 10);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		m_SolarSystem->Draw();

		m_Window->SwapBuffers();
		m_Window->PollEvents();
	}

	m_Window->Close();
}