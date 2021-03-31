build:
	g++ -Wall ./src/*.cpp -lSDL2 -o SimpleDiceC
run:
	./SimpleDiceC
clean:
	rm SimpleDiceC
