OBJS = Main.o HashTable.o
CPPFLAGS = -std=c++11

PROG = WordAnalysis
CC = g++

$(PROG): $(OBJS) 
	$(CC) -o $(PROG) $(OBJS)

Main.o: HashTable.h HashTable.cpp
	$(CC) $(CPPFLAGS) -c Main.cpp 

HashTable.o: HashTable.h HashTable.cpp
	$(CC) $(CPPFLAGS) -c HashTable.cpp

clean:
	$(RM) $(PROG) $(OBJS)