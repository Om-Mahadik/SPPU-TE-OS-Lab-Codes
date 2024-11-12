#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ 27

int main() {
	key_t key = 3708;
	int shmid;
	char *shm;

	if ((shmid = shmget(key, SHMSZ,  0666)) < 0) {
		perror("shmget");
		exit(1);
	}

	shm = shmat(shmid, NULL, 0);

	printf("Message from server: %s\n", shm);

	*shm = '*';
	shmdt(shm);

	return 0;
}
