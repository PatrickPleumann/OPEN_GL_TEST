#pragma once
#include "glad/glad.h"
#include <filesystem>

class Shader
{
public:
	Shader(const std::filesystem::path& filePath, GLenum shaderType);
	~Shader();
	GLuint get() const { return id; }

private:
	GLuint id;
};

