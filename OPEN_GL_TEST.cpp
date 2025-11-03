#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "glm/glm.hpp"
#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "Vertex.hpp"
#include "VertexBuffer.hpp"

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(800, 800, "Test", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		return -2;
	}

	std::vector<Vertex> vertices
	{
		Vertex { .pos = { -0.5f, -0.5f, 0.0f },  .color = { 1.0f, 0.0f, 0.0f, 1.0f } },
		Vertex { .pos = {  0.5f, -0.5f, 0.0f },  .color = { 0.0f, 1.0f, 0.0f, 1.0f } },
		Vertex { .pos = {  0.0f,  0.5f, 0.0f },  .color = { 0.0f, 0.0f, 1.0f, 1.0f } }
	};

	VertexBuffer buffer(vertices);

	Shader vertexShader("VertexShader.glsl", GL_VERTEX_SHADER);
	Shader fragmentShader("FragmentShader.glsl", GL_FRAGMENT_SHADER);

	ShaderProgram shaderProgramID(vertexShader, fragmentShader);

	buffer.bind();
	shaderProgramID.use();
	

	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		//glDrawElements(GL_TRIANGLES,static_cast<GLsizei>(buffer.getIndexCount()),GL_UNSIGNED_INT,NULL);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
