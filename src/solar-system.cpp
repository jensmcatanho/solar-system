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
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"

#include "StandardHeaders.h"

int main(int argc, char **argv) {
	// GLFW initialization
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW." << std::endl;
		return -1;

	}
	std::cout << "GLFW initialized." << std::endl;

	GLFWwindow* window = glfwCreateWindow(1024, 768, "OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	std::cout << "Window and context created." << std::endl;

	// GLEW initialization
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW." << std::endl;
	}

	glfwTerminate();

	return 0;
}
