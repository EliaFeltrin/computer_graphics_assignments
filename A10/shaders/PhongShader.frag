#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragUV;

layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 1) uniform GlobalUniformBufferObject {
	float time;
} gubo;

void main() {
	vec3 Norm = fragNorm;
	
	float y = fragPos.y;
	float t = gubo.time;
	float r = 0.0f, g = 0.0f, b = 0.0f;

	float h = t/3 + y;
	h = h - int(h/6) * 6;

	float c1 = int(h<1),
		c2 = int(h >=1 && h<2),
		c3 = int(h >=2 && h<3),
		c4 = int(h >=3 && h<4),
		c5 = int(h >=4 && h<5),
		c6 = int(h >=5);

		r = 1 		* (c1+c6) 	+
			(2-h) 	* c2 		+ 
			(h-4) 	* c5;

		g = h 		* c1 		+ 
			1		* (c2 + c3) + 
			(4-h)	* c4;

		b = (h-2) 	* c3		+
			1 		* (c4 + c5) +
			(6-h) 	* c6;

	outColor = vec4(r, g, b, 1.0f);
}