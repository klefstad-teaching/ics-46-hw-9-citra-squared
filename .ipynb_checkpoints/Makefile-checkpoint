CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic -fsanitize=address

all: ladder_main

ladder_main: src/ladder_main.cpp src/ladder.o
	g++ $(CXXFLAGS) src/ladder_main.cpp -o ladder_main src/ladder.o
src/ladder.o: src/ladder.cpp
	g++ $(CXXFLAGS) -c src/ladder.cpp -o src/ladder.o

clean:
	/bin/rm src/*.o ladder_main