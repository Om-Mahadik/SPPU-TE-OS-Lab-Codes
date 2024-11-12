#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> 

void sort_asc(int arr[], int n) {
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int arr[n];
	printf("Enter the array elements:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort_asc(arr, n);

	char arr_str[n * 4];
	char temp[10];

	arr_str[0] = '\0';
	for (int i = 0; i < n; i++) {
		sprintf(temp, "%d ", arr[i]);
		strcat(arr_str, temp);
	}

	pid_t pid = fork();
	if (pid == 0) {
		char *argv[] = {"/bin/echo", arr_str, NULL};
		execv("/bin/echo", argv);
		perror("execv failed");
		exit(1);
	} else if (pid > 0) {
		printf("Parent process (Ascending Order):\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		wait(NULL);
	} else {
		perror("Fork failed");
		exit(1);
	}

	return 0;
}
