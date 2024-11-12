#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 20

void bubbleSort(int a[], int n);

int main() {
	pid_t pid;
	int a[MAX], n;
	int i;

    	printf("\n\tEnter the number of elements: ");
    	scanf("%d", &n);
    	printf("\n\tEnter the elements: \n");
	for (i = 0; i < n; i++) {
       		printf("\t");
        	scanf("%d", &a[i]);
    	}

    	pid = fork();

	if (pid < 0) {
        	printf("Error while creating a new process.");
    	}

    	else if (pid == 0) {
	        printf("\nChild Process Started...\n");
		printf("\nIt is a child process with pid=%d and ppid=%d", getpid(), getppid());

        	bubbleSort(a, n);

        	printf("\nSorted array by bubble sort in Child process:\n");
        	for (i = 0; i < n; i++) {
        	    	printf("%d\t", a[i]);
        	}

		printf("\n");
        	printf("\nChild Process Finished\n");
    	}

    	else {
        	printf("\nParent Process Started\n");
        	printf("\nIt is a parent process with pid=%d \n", getpid());

        	bubbleSort(a, n);

	        printf("\n\n\tSorted array by bubble sort (Parent):\n\t");
		for (i = 0; i < n; i++) {
            		printf("%d\t", a[i]);
        	}

        	printf("\n");
        	printf("\nParent Process Finished\n");


	        wait(NULL);
        	printf("\nParent process collected the status of child process.\n");
    	}

    	execl("/bin/ps", "ps", NULL);

    	return 0;
}


void bubbleSort(int a[MAX], int n) {
	int i, j, temp;
    	for (i = 0; i < n - 1; i++) {
        	for (j = 0; j < n - 1 - i; j++) {
            		if (a[j] > a[j + 1]) {
                		temp = a[j];
                		a[j] = a[j + 1];
                		a[j + 1] = temp;
            		}
        	}
    	}
}
