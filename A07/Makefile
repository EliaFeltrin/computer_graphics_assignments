CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A07.cpp
	g++ $(CFLAGS) -o A07 A07.cpp $(LDFLAGS)

.PHONY: test clean

test: A07
	./A07

clean:
	rm -f A07

all:
	rm -f A07
	g++ $(CFLAGS) -o A07 A07.cpp $(LDFLAGS)
	./A07
