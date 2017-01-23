Lab6: main.o MazeReader.o MazeCreationException.o MazeWalker.o
	g++ -std=c++11 -g -Wall main.o MazeReader.o MazeCreationException.o MazeWalker.o -o Lab6

main.o: main.cpp MazeReader.h
	g++ -std=c++11 -g -Wall -c main.cpp

MazeReader.o: MazeReader.h MazeReader.cpp MazeCreationException.h
	g++ -std=c++11 -g -Wall -c MazeReader.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -std=c++11 -g -Wall -c MazeCreationException.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -std=c++11 -g -Wall -c MazeWalker.cpp

clean:
	rm *.o Lab6  
