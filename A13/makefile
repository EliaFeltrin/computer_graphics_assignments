CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A13.cpp
	g++ $(CFLAGS) -o A13 A13.cpp $(LDFLAGS)

.PHONY: test clean

test: A13
	./A13

clean:
	rm -f A13
	rm -f shaders/*.spv

all:
	rm -f A13
	rm -f shaders/BlinnFrag.spv

	glslc shaders/BlinnShader.frag	-o shaders/BlinnFrag.spv


	g++ $(CFLAGS) -o A13 A13.cpp $(LDFLAGS)
	./A13
