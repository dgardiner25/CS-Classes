CPPFLAGS = -g -Wall --pedantic-errors -s

program: main.o list.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c ${CPPFLAGS} $<

clean:
	-@rm -f *.o program

list.o: list.h
main.o: list.h
