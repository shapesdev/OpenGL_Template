#ifndef SHADER_H
#define SHADER_H

#include "GL/glew.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#pragma once
class Shader
{
public:
	unsigned int ID;
	Shader(const char* filePath);
	~Shader();
	void Use();
	void SetBool(const std::string &name, bool value) const;
	void SetInt(const std::string &name, int value) const;
	void SetFloat(const std::string &name, float value) const;

private:
	void CheckCompileErrors(unsigned int shader, std::string type);
};

#endif // !SHADER_H

