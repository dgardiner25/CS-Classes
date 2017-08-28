CPP=$(wildcard *.cpp)
H=$(wildcard *.h)
O=$(CPP:%.cpp=%.o)
COMPILER=g++

program: ${O}
	${COMPILER} ${O} -o program
	
.PHONY: debug
debug: ${O}
	${COMPILER} -g ${O} -o program

.PHONY: clean

clean:
	-@rm -f program
	-@rm -f *.o
