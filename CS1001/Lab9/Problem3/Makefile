CPPFLAGS = -g -Wall --pedantic-errors -s

program: main.o vector.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c ${CPPFLAGS} $<

clean:
	-@rm -f *.o program


main.o: vector.h
vector.o: vector.h
