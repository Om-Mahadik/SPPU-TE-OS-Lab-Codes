#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SHMSZ 27

int main() {
	key_t key = 3708;
	int shmid;
	char *shm;

	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(1);
	}

	shm = shmat(shmid, NULL, 0);

	strcpy(shm, "Hello Bubu!");

	while (*shm != '*') {
		sleep(1);
	}

	shmdt(shm);
	return 0;
}
