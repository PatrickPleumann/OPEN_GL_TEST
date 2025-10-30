#include "Shader.hpp"
#include <fstream>

Shader::Shader(const std::filesystem::path& filePath, GLenum shaderType)
{
	std::ifstream file(filePath);
	std::stringstream s;
	s << file.rdbuf();
	std::string shaderCode = s.str();

	const char* pShaderCode = shaderCode.c_str();

}
