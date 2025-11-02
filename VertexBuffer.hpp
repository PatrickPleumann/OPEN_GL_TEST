#pragma once
#include "glad/glad.h"
#include <vector>
#include "glm/glm.hpp"
#include "Vertex.hpp"

class VertexBuffer
{
public:
	VertexBuffer(const std::vector<Vertex>& vertices);
	void bind();

	size_t getIndexCount() const
	{
		return indexCount;
	}

private:
	static GLuint createVertexArrayObject();
	static GLuint createBuffer();

	GLuint VAO { createVertexArrayObject() };
	GLuint VBO { createBuffer() };
	GLuint EBO { createBuffer() };

	size_t indexCount;
};

