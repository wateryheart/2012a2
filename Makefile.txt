all: 
	g++ -c List.cpp
	g++ -c Polynomial.cpp
	g++ -c main.cpp
	g++ -o pa2 List.o Polynomial.o main.o
clean:
	rm *.o pa2

