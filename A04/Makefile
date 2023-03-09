CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A04.cpp
	g++ $(CFLAGS) -o A04 A04.cpp $(LDFLAGS)

.PHONY: test clean

test: A04
	./A04

clean:
	rm -f A04

all:
	rm -f A04
	g++ $(CFLAGS) -o A04 A04.cpp $(LDFLAGS)
	./A04
