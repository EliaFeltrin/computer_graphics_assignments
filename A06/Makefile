CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A06.cpp
	g++ $(CFLAGS) -o A06 A06.cpp $(LDFLAGS)

.PHONY: test clean

test: A06
	./A06

clean:
	rm -f A06

all:
	rm -f A06
	g++ $(CFLAGS) -o A06 A06.cpp $(LDFLAGS)
	./A06
