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
#include "Camera.h"
#include "Window.h"

template<> Core *Singleton<Core>::m_Instance = nullptr;

Core::Core() :
	m_Window(new Window("Solar System", 1024, 768)),
	m_SolarSystem(new SolarSystem(9)),
	m_Camera(new Camera(0.0f, 0.0f, SUN_RADIUS / glm::tan(glm::radians(22.5f)) + SUN_RADIUS)),
	m_DeltaTime(0.0f) {

}

void Core::Setup() {
	m_Window->Create();

	// GLEW initialization
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW." << std::endl;
	}

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	m_SolarSystem->Start();
	m_SolarSystem->Load();
}

void Core::Run() {
	GLfloat current_frame = 0.0f;
	GLfloat last_frame = 0.0f;

	while (!glfwWindowShouldClose(m_Window->GetPointer())) {
		current_frame = glfwGetTime();
		m_DeltaTime = current_frame - last_frame;
		last_frame = current_frame;

		m_Window->DisplayFPS();
		m_Window->ProcessInput();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 projection_matrix = glm::perspective(static_cast<double>(glm::radians(m_Camera->m_Zoom)), static_cast<double>(m_Window->m_AspectRatio), 0.0001, 10000.0);
		glm::mat4 view_matrix = m_Camera->GetViewMatrix();;

		m_SolarSystem->Draw(projection_matrix * view_matrix);

#if 0
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif
		m_Window->SwapBuffers();
		m_Window->PollEvents();
	}

	m_Window->Close();
}

std::stringstream Core::ReadFile(std::string path) {
	std::ifstream file;
	std::stringstream string_stream;

	file.exceptions(std::ifstream::badbit);

	try {
		file.open(path);
		string_stream << file.rdbuf();
		file.close();

	} catch (std::ifstream::failure e) {
		std::cerr << "Error while reading the file. (Does the file exist?)" << std::endl;
	}

	return string_stream;
}

Core &Core::GetSingleton() {
	return *m_Instance;
}

Core *Core::GetSingletonPtr() {
	return m_Instance;
}