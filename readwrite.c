#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
sem_t wrt;
pthread_mutex_t mutex;
int cnt = 0;
int numreader = 0;
void* writer(void* wno) {
	sem_wait(&wrt);
	cnt++;
	printf("Writer %d modified cnt to %d\n", *((int*)wno), cnt);
	sem_post(&wrt);
	return NULL;
}
void* reader(void* rno) {
	pthread_mutex_lock(&mutex);
	numreader++;
	if (numreader == 1) {
		sem_wait(&wrt);
	}
	pthread_mutex_unlock(&mutex);
	printf("Reader %d read cnt as %d\n", *((int*)rno), cnt);
	pthread_mutex_lock(&mutex);
	numreader--;
	if (numreader == 0) {
		sem_post(&wrt);
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}
int main() {
	pthread_t read[5], write[3];
	int a[5] = {1, 2, 3, 4, 5};
	pthread_mutex_init(&mutex, NULL);
	sem_init(&wrt, 0, 1);
	for (int i = 0; i < 5; i++) {
		pthread_create(&read[i], NULL, reader, (void*)&a[i]);
	}
	for (int i = 0; i < 3; i++) {
		pthread_create(&write[i], NULL, writer, (void*)&a[i]);
	}
	for (int i = 0; i < 5; i++) {
		pthread_join(read[i], NULL);
	}
	for (int i = 0; i < 3; i++) {
		pthread_join(write[i], NULL);
	}
	pthread_mutex_destroy(&mutex);
	sem_destroy(&wrt);
	return 0;
}
