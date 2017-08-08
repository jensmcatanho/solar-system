#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"

#include <iostream>

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
