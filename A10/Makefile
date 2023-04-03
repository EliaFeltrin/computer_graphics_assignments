CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A10.cpp
	g++ $(CFLAGS) -o A10 A10.cpp $(LDFLAGS)

.PHONY: test clean

test: A10
	./A10

clean:
	rm -f A10
	rm -f shaders/*.spv

all:
	rm -f A10
	rm -f shaders/*.spv
	glslc shaders/PhongShader.frag -o shaders/PhongFrag.spv
	glslc shaders/PhongShader.vert -o shaders/PhongVert.spv
	g++ $(CFLAGS) -o A10 A10.cpp $(LDFLAGS)
	./A10
