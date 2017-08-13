#version 330 core

in vec2 TexCoord;

uniform sampler2D in_texture;

out vec4 FragColor;

void main() {
	FragColor = texture(in_texture, TexCoord);
}