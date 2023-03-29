CC = g++

main: main.cpp sort.o max.o min.o
	$(CC) main.cpp sort.o max.o min.o -o main

sort.o: sort.cpp
	$(CC) -c sort.cpp

max.o: max.cpp
	$(CC) -c max.cpp

min.o: min.cpp
	$(CC) -c min.cpp

clean:
	rm *.o main