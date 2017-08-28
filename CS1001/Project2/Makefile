.PHONY: clean

word_count: stl.o
	g++ stl.o -o word_count
	
stl.o: stl.cpp
	g++ -c -std=c++11 stl.cpp


clean:
	-@rm -f *.o
