CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -I. -I./headers

VulkanTest: A03.cpp
	rm -f A03
	g++ $(CFLAGS) -o A03 A03.cpp $(LDFLAGS)

.PHONY: test clean

test: A03
	rm -f A03
	g++ $(CFLAGS) -o A03 A03.cpp $(LDFLAGS)
	./A03

clean:
	rm -f A03
