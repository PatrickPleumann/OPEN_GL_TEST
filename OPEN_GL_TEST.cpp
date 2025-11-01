#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "glm/glm.hpp"
#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "Vertex.hpp"

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

	Vertex vertices[3] = {

	{.pos = { 0.5f, -0.5f, 0.0f},  .color = { 0.3f, 0.2f, 0.1f, 1.0f }},
	{.pos = { 0.5f, -0.5f, 0.0f},  .color = { 0.5f, 0.2f, 0.3f, 1.0f }},
	{.pos = { 0.0f,  0.5f, 0.0f},  .color = { 0.2f, 0.1f, 0.3f, 1.0f }}
	};


	//TODO: Hier wird einmal die Blaupause für den (einzelnen) VertexShader angelegt   >> in Klasse auslagern, weil es soll ja mehrere Shader geben.
	const char* vertexShader = "#version 330 core \n layout (location = 0) in vec3 pos;layout(location = 1) in vec4 col; void main() { gl_Position = vec4(pos, 1.0); }";
	GLuint vertexID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexID, 1, &vertexShader, NULL);
	glCompileShader(vertexID);

	//TODO: Hier wird einmal die Blaupause für den (einzelnen) Fragment angelegt    >> in Klasse auslagern, weil es soll ja mehrere Shader geben.
	const char* fragmentShader = "#version 330 core \n in vec4 col; out vec4 FragColor; void main() { FragColor = col; }";
	GLuint fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentID, 1, &fragmentShader, NULL);
	glCompileShader(fragmentID);

	//TODO: Hier wird ein ShaderProgram angelegt und dann werden vertexID und fragmentID dem ShaderProgram hinzugefügt >> auslagern.
	GLuint shaderProgramID = glCreateProgram();



	glAttachShader(shaderProgramID, vertexID);
	glAttachShader(shaderProgramID, fragmentID);

	//unser ShaderProgram ist einigermaßen befüllt und muss jetzt mit open gl gelinkt werden
	glLinkProgram(shaderProgramID);

	GLuint VAO{}; //hier kommen VBO & EBO rein
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Buffer erzeugen und generieren,
	GLuint VBO{}; //hier kommen Vertices rein
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint EBO{}; // hier kommen die indices rein
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Vertex),0, GL_STATIC_DRAW );

	glBindAttribLocation(shaderProgramID, 0, "pos");
	glBindAttribLocation(shaderProgramID, 1, "color");

	//das Shader Program, was ich vorher gelinkt habe, wird jetzt benutzt.
	glUseProgram(shaderProgramID);


	//Attribute für die Vertex einpflegen
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), /*reinterpret_cast<void*>(offsetof(Vertex, Vertex::pos))*/(void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Vertex::color)));
	glEnableVertexAttribArray(1);

	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
