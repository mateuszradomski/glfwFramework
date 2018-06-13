#include <iostream> // for cout

#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
	GLFWwindow* window;

	/* Initializaing GLFW */
	if (!glfwInit())
	{
		std::cout << "[ERROR]: Failed to load GLFW\n";
		return -1;
	}

	/* Pointing the window pointer to a window object */ 
	window = glfwCreateWindow(800, 800, "Snake game", NULL, NULL);

	/* Basic error checking if the window was created succefully */
	if (window == NULL)
	{
		std::cout << "[ERROR]: Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}

	/* Making the window poniter as the current openGL context */
	glfwMakeContextCurrent(window);

	/* Error checking for initializaing GLEW */ 
	if(glewInit())
	{
		std::cout << "[ERROR]: Failed to load GLEW\n";
		return -1;
	}

	glClearColor(0.3f, 1.0f, 1.0f, 1.0f);

	while(!glfwWindowShouldClose(window))
	{
		/* Clearing the screen with set color */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swaping the current buffer that is on the screen with a new one */
		glfwSwapBuffers(window);

		/* Polling the events that happend */
		glfwPollEvents();
	}

	/* Cleaning GLFW up */
	glfwTerminate();
	return 0;
}
