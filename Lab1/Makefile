VotingRecords: main.o Executive.o VoterRegistrationRecord.o
	g++ -std=c++11 -g -Wall main.o Executive.o VoterRegistrationRecord.o -o VotingRecords

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp VoterRegistrationRecord.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

VoterRegistrationRecord.o: VoterRegistrationRecord.h VoterRegistrationRecord.cpp
	g++ -std=c++11 -g -Wall -c VoterRegistrationRecord.cpp

clean:
	rm *.o VotingRecords  
