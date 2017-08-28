.PHONY: clean

program: main.o TrianglePrinter.o funcs.o
	g++ main.o TrianglePrinter.o funcs.o -o program

main.o: main.cpp TrianglePrinter.h funcs.h
	g++ -c main.cpp
	
TrianglePrinter.o: TrianglePrinter.cpp TrianglePrinter.h
	g++ -c TrianglePrinter.cpp
	
funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp
	
clean:
	-@rm -f program
	-@rm -f *.o
