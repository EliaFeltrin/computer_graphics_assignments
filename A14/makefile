CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A14.cpp
	g++ $(CFLAGS) -o A14 A14.cpp $(LDFLAGS)

.PHONY: test clean

test: A14
	./A14

clean:
	rm -f A14

all:
	rm -f A14

	g++ $(CFLAGS) -o A14 A14.cpp $(LDFLAGS)
	./A14
