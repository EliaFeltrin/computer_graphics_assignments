CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A01.cpp
	g++ $(CFLAGS) -o cat A01.cpp $(LDFLAGS)

.PHONY: test clean

test: cat
	./cat

clean:
	rm -f cat
