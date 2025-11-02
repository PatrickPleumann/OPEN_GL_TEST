#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram(const Shader& vertexShader, const Shader& fragmentShader)
	: id{ glCreateProgram() }
{
	glAttachShader(id, GL_VERTEX_SHADER);
	glAttachShader(id, GL_FRAGMENT_SHADER);

	glLinkProgram(id);

}

void ShaderProgram::use() const
{
	glUseProgram(id);
}
