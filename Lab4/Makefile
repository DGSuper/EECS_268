Elevators: main.o BuildingExecutive.o PreconditionViolatedException.o
	g++ -std=c++11 -g -Wall main.o BuildingExecutive.o PreconditionViolatedException.o -o Elevators

main.o: main.cpp BuildingExecutive.h
	g++ -std=c++11 -g -Wall -c main.cpp

BuildingExecutive.o: BuildingExecutive.h BuildingExecutive.cpp StackInterface.h Stack.h Stack.hpp QueueInterface.h Queue.h Queue.hpp
	g++ -std=c++11 -g -Wall -c BuildingExecutive.cpp

PreconditionViolatedException.o: PreconditionViolatedException.h PreconditionViolatedException.cpp
	g++ -std=c++11 -g -Wall -c PreconditionViolatedException.cpp

clean:
	rm *.o Elevators  
