Lab8: main.o Executive.o Pokemon.o NotFoundException.o
	g++ -std=c++11 -g -Wall main.o Executive.o Pokemon.o NotFoundException.o -o Lab8
	
main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp
	
Executive.o: Executive.h Executive.cpp Pokemon.h
	g++ -std=c++11 -g -Wall -c Executive.cpp
	
Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp
	
NotFoundException.o: NotFoundException.h NotFoundException.cpp
	g++ -std=c++11 -g -Wall -c NotFoundException.cpp

clean:
	rm *.o Lab8  
