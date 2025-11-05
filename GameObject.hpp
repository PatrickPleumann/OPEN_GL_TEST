#pragma once
#include <vector>
#include "glm/glm.hpp"
#include "Vertex.hpp"
#include "GlobalShader.hpp"
#include "VertexBuffer.hpp"
#include "Component.hpp"
#include "memory.h"
#include "Transform.hpp"

class GameObject
{
public:

	GameObject(std::vector<Vertex> vertices) : vertices{ vertices }
	{

		InitializeGameObject();
	}

private:

	void InitializeGameObject()
	{
		buffer.InitializeComponent();
		shader.InitializeComponent();
	}

	std::vector<Vertex> vertices; // 3D Model

	GlobalShader shader{};
	VertexBuffer buffer{ vertices };

	std::vector<Component> components = { buffer ,shader };
	//Transform

};

