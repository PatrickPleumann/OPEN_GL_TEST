#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram(const Shader& vertexShader, const Shader& fragmentShader)
	: id{ glCreateProgram() }
{
	glAttachShader(id, vertexShader.get());
	glAttachShader(id, fragmentShader.get());

	glLinkProgram(id);
}

void ShaderProgram::use() const
{
	glUseProgram(id);
}
