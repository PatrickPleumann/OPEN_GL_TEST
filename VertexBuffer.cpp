#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(const std::vector<Vertex>& vertices)
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Vertex::pos)));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Vertex::color)));
	glEnableVertexAttribArray(1);

}

void VertexBuffer::bind()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

GLuint VertexBuffer::createVertexArrayObject()
{
	GLuint id;
	glGenVertexArrays(1, &id);
	return id;
}

GLuint VertexBuffer::createBuffer()
{
	GLuint id;
	glGenBuffers(1, &id);
	return id;
}
