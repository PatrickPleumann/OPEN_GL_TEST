#include "Shader.hpp"
#include <fstream>

Shader::Shader(const std::filesystem::path& filePath, GLenum shaderType)
	: id(glCreateShader(shaderType))
{
	std::ifstream file(filePath);
	std::stringstream stream;
	stream << file.rdbuf();
	std::string shaderCode = stream.str();

	const char* pShaderCode = shaderCode.c_str();

	glShaderSource(id, 1, &pShaderCode, nullptr);
	glCompileShader(id);
}

Shader::~Shader()
{
	glDeleteShader(id);
}
