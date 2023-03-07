CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A02.cpp
	g++ $(CFLAGS) -o bulldog A02.cpp $(LDFLAGS)

.PHONY: test clean

test: bulldog
	./bulldog

clean:
	rm -f bulldog
