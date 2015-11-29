CXXFLAGS=-std=c++11 -g -fPIC

TARGETS = 

all: $(TARGETS)

%.o: %.cpp field.hpp player.hpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.o $(TARGETS)
