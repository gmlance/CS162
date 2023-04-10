


out: main.o funcdef.o
	g++ main.o funcdef.o -o out

main.o: main.cpp
	g++ -c main.cpp

funcdef.o: funcdef.cpp
	g++ -c funcdef.cpp


clean:
	rm -f *.o out
