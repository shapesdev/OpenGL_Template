#shader vertex
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 ourColor;
out vec3 ourPosition;

uniform float offset;

void main()
{
	gl_Position = vec4(aPos.x + offset, aPos.y, aPos.z, 1.0f);
	ourColor = aColor;
	ourPosition = aPos;
}

#shader fragment
#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec3 ourPosition;

void main()
{
	FragColor = vec4(ourPosition, 1.0f);
}