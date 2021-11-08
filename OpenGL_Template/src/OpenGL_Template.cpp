#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

void ProcessInput(GLFWwindow* window);
void Framebuffer_size_callback(GLFWwindow* window, int width, int height);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	// GLFW Initialization
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// GLFW window creation
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Template", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, Framebuffer_size_callback);

	// GLEW Initalization (only after the context is set)
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed loading GLEW!" << std::endl;
	}

	// Render loop
	while (!glfwWindowShouldClose(window)) {
		//Input
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}

		//Rendering commands here
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // State setting function
		glClear(GL_COLOR_BUFFER_BIT); // State using function

		//Check and call events and swap the buffers (Double Buffer)
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

// GLFW: Query all relevant input (key presses/releases)
void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// GLFW: execute whenever the window size changes
void Framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}