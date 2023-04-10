


out: main.o gml.o
	g++ main.o gml.o -o out

main.o: main.cpp
	g++ -c main.cpp

gml.o: gml.cpp
	g++ -c gml.cpp


clean:
	rm -f *.o out
