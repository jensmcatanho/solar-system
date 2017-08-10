#version 330 core

layout(location = 0) in vec3 in_Position;
layout(location = 1) in vec3 in_Normal;
layout(location = 2) in vec2 in_TexCoord;

uniform mat4 un_mvpMatrix;

out vec2 out_TexCoord;

void main() {
	gl_Position = un_mvpMatrix * vec4(in_Position, 1.0);

	out_TexCoord = in_TexCoord;
}