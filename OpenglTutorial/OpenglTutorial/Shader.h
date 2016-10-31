#pragma once

#include <string>
#include <GL\glew.h>

using namespace std;

class Shader
{
public:
	Shader(const string& filename);
	void Bind();
	virtual ~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;

	string LoadShader(const string& filename);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);
	GLuint CreateShader(const string& text, unsigned int type);

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
};

