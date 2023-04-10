Out: main.o animal.o zoo.o sealion.o tiger.o bear.o
		g++ main.o animal.o zoo.o sealion.o tiger.o bear.o -o output


main.o: main.cpp
		g++ main.cpp
		
animal.o: animal.cpp animal.h
		g++ animal.cpp
		
sealion.o: sealion.cpp sealion.h
		g++ sealion.cpp
		
tiger.o: tiger.cpp tiger.h
		g++ tiger.cpp
		
bear.o: bear.cpp bear.h
		g++ bear.cpp
		
Clean:
		rm -f *.o output

