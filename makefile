
run: main
	./main

main: main.cpp ttobsi.h vecmath.h
	g++ main.cpp -Wall -Wextra -lSDL2 -o main