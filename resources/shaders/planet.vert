#version 430 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Normal;
layout(location = 2) in vec2 a_TexCoord;

layout(location = 3) uniform mat4 u_ModelMatrix;
layout(location = 4) uniform mat4 u_mvpMatrix;

out vec3 vs_FragPosition;
out vec3 vs_Normal;
out vec2 vs_TexCoord;

void main() {
	gl_Position = u_mvpMatrix * vec4(a_Position, 1.0);

	vs_FragPosition = vec3(u_ModelMatrix * vec4(a_Position, 1.0));
	vs_TexCoord = a_TexCoord;
	vs_Normal = mat3(transpose(inverse(u_ModelMatrix))) * a_Normal;
}