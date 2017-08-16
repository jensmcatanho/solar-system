#version 330 core

in vec2 TexCoord;

uniform sampler2D in_Texture;

out vec4 FragColor;

void main() {
	FragColor = texture(in_Texture, TexCoord);
}