.PHONY: all clean

SRC = main.cpp Circle.cpp Ellipse.cpp Helix.cpp

all: out
	
clean:
	rm -rf out *.o

out: $(SRC)
	g++ $(SRC) -o out