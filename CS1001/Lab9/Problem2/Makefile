CPPFLAGS = -g -Wall --pedantic-errors -s

program: main.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c ${CPPFLAGS} $<

clean:
	-@rm -f *.o program


main.o: dtor.h plain.h
