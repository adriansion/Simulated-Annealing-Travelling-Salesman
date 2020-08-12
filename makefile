optimize: queue.o matrix.o readfile.o distances.o simulated-annealing.o main.o
	@gcc -o optimize queue.o matrix.o  readfile.o distances.o simulated-annealing.o main.o -lm
	@rm -f *.o

queue.o: queue.c queue.h
	@gcc -c queue.c

matrix.o: matrix.c matrix.h
	@gcc -c matrix.c

readfile.o: readfile.c readfile.h
	@gcc -c readfile.c

distances.o: distances.c distances.h
	@gcc -c distances.c

simulated-annealing.o: simulated-annealing.c simulated-annealing.h
	@gcc -c simulated-annealing.c

main.o: main.c simulated-annealing.h
	@gcc -c main.c

clean:
	@rm -f *.o
