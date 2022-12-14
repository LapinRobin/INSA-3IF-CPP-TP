# enable g flag to use debugging tool, 
# enable DMAP flag to print constructor / destructor message in terminal
cppFlags:=-g -ansi -pedantic -Wall -std=c++11 -DMAP

main: main.o Cell.o ListeChainee.o Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o
	g++ $(cppFlags) -o main main.o Cell.o ListeChainee.o Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o

main.o: main.cpp
	g++ $(cppFlags) -c main.cpp

Cell.o: Cell.cpp
	g++ $(cppFlags) -c Cell.cpp

ListeChainee.o: ListeChainee.cpp
	g++ $(cppFlags) -c ListeChainee.cpp

Catalogue.o: Catalogue.cpp
	g++ $(cppFlags) -c Catalogue.cpp

TrajetSimple.o: TrajetSimple.cpp
	g++ $(cppFlags) -c TrajetSimple.cpp

TrajetCompose.o: TrajetCompose.cpp
	g++ $(cppFlags) -c TrajetCompose.cpp

Trajet.o: Trajet.cpp
	g++ $(cppFlags) -c Trajet.cpp

.PHONY : clean
clean :
	rm *.o
