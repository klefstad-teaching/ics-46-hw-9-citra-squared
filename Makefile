CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic -fsanitize=address

all: ladder_main dijkstras_main

ladder_main: src/ladder_main.cpp src/ladder.o
	g++ $(CXXFLAGS) src/ladder_main.cpp -o ladder_main src/ladder.o
src/ladder.o: src/ladder.cpp
	g++ $(CXXFLAGS) -c src/ladder.cpp -o src/ladder.o

dijkstras_main: src/dijkstras_main.cpp src/dijkstras.o
	g++ $(CXXFLAGS) src/dijkstras_main.cpp -o dijkstras_main src/dijkstras.o
src/dijkstras.o: src/dijkstras.cpp
	g++ $(CXXFLAGS) -c src/dijkstras.cpp -o src/dijkstras.o

clean:
	/bin/rm src/*.o ladder_main dijkstras_main