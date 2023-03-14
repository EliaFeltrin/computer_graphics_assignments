CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A05.cpp
	g++ $(CFLAGS) -o A05 A05.cpp $(LDFLAGS)

.PHONY: test clean

test: A05
	./A05

clean:
	rm -f A05

all:
	rm -f A05
	g++ $(CFLAGS) -o A05 A05.cpp $(LDFLAGS)
	./A05
