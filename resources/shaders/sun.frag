#version 430 core

struct Material {
    sampler2D diffuse;
    sampler2D specular;
}; 

in vec3 vs_FragPosition;
in vec3 vs_Normal;
in vec2 vs_TexCoord;

layout(location = 5) uniform Material u_Material;

out vec4 FragColor;

void main() {
	vec3 diffuse = texture(u_Material.diffuse, vs_TexCoord).rgb;
	vec3 specular = texture(u_Material.specular, vs_TexCoord).rgb;

	FragColor = vec4(diffuse + specular, 1.0);
}