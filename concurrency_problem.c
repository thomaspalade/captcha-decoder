#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>

int a;
pthread_mutex_t lock;

void* threadFunction1(void *var)
{
	pthread_mutex_lock(&lock);
	for (int i = 0; i < 100; i++)
		a = a + 2;
	pthread_mutex_unlock(&lock);
}

void* threadFunction2(void *var)
{
	pthread_mutex_lock(&lock);
	// for (int i = 0; i < 100; i++)
		a = a + 3;
	pthread_mutex_unlock(&lock);
}

int main(int argc, char **argv)
{
	int P = 2;
	int i;

	pthread_t tid[P];
	int thread_id[P];
	for(i = 0; i < P; i++)
		thread_id[i] = i;

	pthread_create(&(tid[0]), NULL, threadFunction1, &(thread_id[0]));
	pthread_create(&(tid[1]), NULL, threadFunction1, &(thread_id[1]));

	for(i = 0; i < P; i++) {
		pthread_join(tid[i], NULL);
	}

	printf("%d", a);

	return 0;
}
