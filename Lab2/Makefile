Infection: main.o MedicalExecutive.o City.o
	g++ -std=c++11 -g -Wall main.o MedicalExecutive.o City.o -o Infection
	
main.o: main.cpp MedicalExecutive.h
	g++ -std=c++11 -g -Wall -c main.cpp

MedicalExecutive.o: MedicalExecutive.h MedicalExecutive.cpp City.h
	g++ -std=c++11 -g -Wall -c MedicalExecutive.cpp
	
City.o: City.h City.cpp
	g++ -std=c++11 -g -Wall -c City.cpp

clean:
	rm *.o Infection  
