CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm


run:
	./main

fast_run: clean build_johnson
	./main

build_floyd: algo1.o main.o
	g++ algo1.o main.o -o main $(CFLAGS)	

build_bellman: algo2.o main.o
	g++ algo2.o main.o -o main $(CFLAGS)

build_johnson: algo3.o main.o
	g++ algo3.o main.o -o main $(CFLAGS)

build_dijkstra: algo4.o main.o
	g++ algo4.o main.o -o main $(CFLAGS)

algo1.o: algo1.cpp
	g++ algo1.cpp -c $(CFLAGS)

algo2.o: algo2.cpp
	g++ algo2.cpp -c $(CFLAGS)

algo3.o: algo3.cpp
	g++ algo3.cpp -c $(CFLAGS)

algo4.o: algo4.cpp
	g++ algo4.cpp -c $(CFLAGS)	

main.o: main.cpp
	g++ main.cpp -c $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o main
