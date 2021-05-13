#making the executable
all: main.cpp
	g++ -c main.cpp
	g++ main.o -o FluidSim2D -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm -f *.o
	rm -f FluidSim2D
