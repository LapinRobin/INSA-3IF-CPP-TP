CPPFLAGS=-Wall -g -std=c++11
objects=analog.o Flux.o Stats.o
path=../bin

# compile the executable analog to the path ../bin
$(path)/analog : $(objects)
	g++ $(CPPFLAGS) -o $(path)/analog $(objects)

# clean object files and executable analog
.PHONY : clean
clean :
	rm $(path)/analog $(objects)