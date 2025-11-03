#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram(const Shader& vertexShader, const Shader& fragmentShader)
	: id{ glCreateProgram() }
{
	glAttachShader(id, vertexShader.get());
	glAttachShader(id, fragmentShader.get());

	glLinkProgram(id);

	glDetachShader(id, vertexShader.get());
	glDetachShader(id, fragmentShader.get());
}

void ShaderProgram::use() const
{
	glUseProgram(id);
}
