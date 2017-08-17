#version 430 core

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 vs_FragPosition;
in vec3 vs_Normal;
in vec2 vs_TexCoord;

layout(location = 5) uniform vec3 u_CameraPosition;
layout(location = 6) uniform Material u_Material;
layout(location = 9) uniform Light u_Light;

out vec4 FragColor;

void main() {
	vec3 ambient = u_Light.ambient * texture(u_Material.diffuse, vs_TexCoord).rgb;

	vec3 normal = normalize(vs_Normal);
	vec3 light_dir = normalize(u_Light.position - vs_FragPosition);
	vec3 diffuse = u_Light.diffuse * max(dot(normal, light_dir), 0.0) * texture(u_Material.diffuse, vs_TexCoord).rgb;

	vec3 specular;

	if (diffuse != vec3(0.0)) {
		vec3 view_dir = normalize(u_CameraPosition - vs_FragPosition);
		vec3 reflection_dir = reflect(-light_dir, normal);
		float spec = pow(max(dot(view_dir, reflection_dir), 0.0), u_Material.shininess);
		specular = u_Light.specular * spec * texture(u_Material.specular, vs_TexCoord).rgb;
	}

	FragColor = vec4(ambient + diffuse + specular, 1.0);
}