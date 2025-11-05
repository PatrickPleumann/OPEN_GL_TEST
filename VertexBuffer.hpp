#pragma once
#include "glad/glad.h"
#include "Vertex.hpp"
#include <vector>
#include "Component.hpp"

class VertexBuffer : public Component
{
public:
	VertexBuffer(const std::vector<Vertex> vertices);
	void InitializeComponent() override; // Component
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

