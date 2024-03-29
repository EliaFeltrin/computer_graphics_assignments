#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec4 fragTan;
layout(location = 3) in vec2 fragUV;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D tex;
layout(binding = 3) uniform sampler2D normMap;
layout(binding = 4) uniform sampler2D matMap;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;
	vec4 lightColor;
	vec3 eyePos;
} gubo;

vec3 BRDF(vec3 V, vec3 N, vec3 L, vec3 Md, float F0, float metallic, float roughness) {
	//vec3 V  - direction of the viewer
	//vec3 N  - normal vector to the surface
	//vec3 L  - light vector (from the light model)
	//vec3 Md - main color of the surface
	//float F0 - Base color for the Fresnel term
	//float metallic - parameter that mixes the diffuse with the specular term.
	//                 in particular, parmeter K seen in the slides is: float K = 1.0f - metallic;
	//float roughness - Material roughness (parmeter rho in the slides).
	//specular color Ms is not passed, and implicitely considered white: vec3 Ms = vec3(1.0f);

	float rho2 = pow(roughness, 2);

	vec3 H = normalize(V + L);	

	float NXH = clamp(dot(N, H), 0, 1);
	float VXH = clamp(dot(V, H), 0, 1);
	float VXN = dot(V, N);
	float LXN = dot(L, N);
	float VXN2 = pow(VXN, 2);
	float LXN2 = pow(LXN, 2);

	float geom = 4 / ((1 + sqrt(1 + rho2 * (1 - VXN2) / VXN2)) * (1 + sqrt(1 + rho2 * (1 - LXN2) / LXN2)));

	float norm = rho2 / (3.14159265359f * pow(NXH*NXH*(rho2 - 1) + 1, 2)); 

	float fred = F0 + (1 - F0) * pow(1 - VXH, 5);

	vec3 diff = Md * max(LXN, 0);

	vec3 spec = vec3(1.0f) * geom * norm * fred / (4 * clamp(VXN, 0, 1));

	return diff * (1-metallic) + spec * (metallic);
}

void main() {
	vec3 Norm = normalize(fragNorm);
	vec3 Tan = normalize(fragTan.xyz - Norm * dot(fragTan.xyz, Norm));
	vec3 Bitan = cross(Norm, Tan) * fragTan.w;
	mat3 tbn = mat3(Tan, Bitan, Norm);
	vec4 nMap = texture(normMap, fragUV);
	vec3 N = normalize(tbn * (nMap.rgb * 2.0 - 1.0));

	vec3 albedo = texture(tex, fragUV).rgb;

	vec4 MRAO = texture(matMap, fragUV);
	float roughness = MRAO.g;
	float ao = MRAO.b;
	float metallic = MRAO.r;
	
	vec3 L = gubo.lightDir;
	vec3 lightColor = gubo.lightColor.rgb;

	vec3 V = normalize(gubo.eyePos - fragPos);

	vec3 DiffSpec = BRDF(V, N, L, albedo, 0.3f, metallic, roughness);
	vec3 Ambient = albedo * 0.05f * ao;
	
	outColor = vec4(clamp(0.95 * DiffSpec * lightColor.rgb + Ambient,0.0,1.0), 1.0f);
}