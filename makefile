
run: main
	./main

main: main.cpp ttobsi.h vecmath.h
	g++ main.cpp -Wall -Wextra -lSDL2 -o main

vecmath_test: tests/vecmath_1.cpp vecmath.h
	g++ tests/vecmath_1.cpp -I. -Wall -Wextra -lSDL2 -o tests/vecmath_1

