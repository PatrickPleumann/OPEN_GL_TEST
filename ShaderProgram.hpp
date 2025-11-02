#pragma once
#include "Shader.hpp"
class ShaderProgram
{
public:
	ShaderProgram(const Shader& vertexShader, const Shader& fragmentShader);
	GLuint get() const { return id; }
	void use() const;

private:
	GLuint id;
};

