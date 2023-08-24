CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A12.cpp
	g++ $(CFLAGS) -o A12 A12.cpp $(LDFLAGS)

.PHONY: test clean

test: A12
	./A12

clean:
	rm -f A12
	rm -f shaders/*.spv

all:
	rm -f A12
	rm -f shaders/PhongFrag.spv
	rm -f shaders/OrenNayarFrag.spv
	rm -f shaders/BlinnNormMapFrag.spv
	rm -f shaders/GGXNornMapFrag.spv

	glslc shaders/PhongShader.frag 			-o shaders/PhongFrag.spv
	glslc shaders/OrenNayarShader.frag		-o shaders/OrenNayarFrag.spv
	glslc shaders/BlinnNormMapShader.frag	-o shaders/BlinnNormMapFrag.spv
	glslc shaders/GGXNormMapShader.frag		-o shaders/GGXNormMapFrag.spv


	g++ $(CFLAGS) -o A12 A12.cpp $(LDFLAGS)
	./A12
