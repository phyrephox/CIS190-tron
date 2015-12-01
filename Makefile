CXXFLAGS=-std=c++11 -g -fPIC

OBJECTS=main.o field.o game.o player.o

TARGETS = tron

all: $(TARGETS)

tron: $(OBJECTS)
	$(CXX) $(OBJECTS) -o tron -g -lglut -lGL -lGLU

%.o: %.cpp field.hpp player.hpp game.hpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.o $(TARGETS)
