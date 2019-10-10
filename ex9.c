#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

int a;
pthread_barrier_t barrier;

void* threadFunction1(void *var)
{
	printf("1");
	pthread_barrier_wait(&barrier);
}

void* threadFunction2(void *var)
{
	pthread_barrier_wait(&barrier);
	printf("2");
}

int main(int argc, char **argv)
{
	int P = 2;
	int i;

	pthread_t tid[P];
	int thread_id[P];
	for(i = 0; i < P; i++)
		thread_id[i] = i;

	pthread_barrier_init(&barrier, NULL, 2);
	
	pthread_create(&(tid[0]), NULL, threadFunction1, &(thread_id[0]));
	pthread_create(&(tid[1]), NULL, threadFunction2, &(thread_id[1]));

	for(i = 0; i < P; i++) {
		pthread_join(tid[i], NULL);
	}

	pthread_barrier_destroy(&barrier);

	return 0;
}
