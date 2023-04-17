CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A11.cpp
	g++ $(CFLAGS) -o A11 A11.cpp $(LDFLAGS)

.PHONY: test clean

test: A11
	./A11

clean:
	rm -f A11
	rm -f shaders/*.spv

all:
	rm -f A11
	rm -f shaders/BlinnFrag1.spv shaders/BlinnFrag2.spv shaders/BlinnFrag3.spv
	glslc shaders/BlinnShader1.frag -o shaders/BlinnFrag1.spv
	glslc shaders/BlinnShader2.frag -o shaders/BlinnFrag2.spv
	glslc shaders/BlinnShader3.frag -o shaders/BlinnFrag3.spv
	g++ $(CFLAGS) -o A11 A11.cpp $(LDFLAGS)
	./A11
