Lab9: main.o Executive.o Patient.o EmptyHeap.o EmptyPriorityQueue.o
	g++ -std=c++11 -g -Wall main.o Executive.o Patient.o EmptyHeap.o EmptyPriorityQueue.o -o Lab9

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Patient.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Patient.o: Patient.h Patient.cpp
	g++ -std=c++11 -g -Wall -c Patient.cpp

EmptyHeap.o: EmptyHeap.h EmptyHeap.cpp
	g++ -std=c++11 -g -Wall -c EmptyHeap.cpp

EmptyPriorityQueue.o: EmptyPriorityQueue.h EmptyPriorityQueue.cpp
	g++ -std=c++11 -g -Wall -c EmptyPriorityQueue.cpp

clean:
	rm *.o Lab9  
