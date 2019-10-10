compile: concurrency_problem.c
	gcc -o concurrency_problem concurrency_problem.c -lm -lpthread

clean:
	rm concurrency_problem
