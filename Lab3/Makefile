Lab3: main.o Executive.o Math.o CannotDetermineRoomDimensions.o NegativeDiscriminant.o NoIntersection.o
	g++ -std=c++11 -g -Wall main.o Executive.o Math.o CannotDetermineRoomDimensions.o NegativeDiscriminant.o NoIntersection.o -o Lab3

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Math.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Math.o: Math.h Math.cpp MathToolsInterface.h
	g++ -std=c++11 -g -Wall -c Math.cpp

CannotDetermineRoomDimensions.o: CannotDetermineRoomDimensions.h CannotDetermineRoomDimensions.cpp
	g++ -std=c++11 -g -Wall -c CannotDetermineRoomDimensions.cpp

NegativeDiscriminant.o: NegativeDiscriminant.h NegativeDiscriminant.cpp
	g++ -std=c++11 -g -Wall -c NegativeDiscriminant.cpp

NoIntersection.o: NoIntersection.h NoIntersection.cpp
	g++ -std=c++11 -g -Wall -c NoIntersection.cpp

clean:
	rm *.o Lab3  
