#include <stdio.h>
#define MAX 10

typedef struct {
	int id, arrival, burst, remaining, completion, waiting, turnaround;
} Process;

void round_robin(Process p[], int n, int time_quantum) {
	int time = 0, completed = 0, i = 0, anyProcessExecuted;

	while (completed != n) {
		anyProcessExecuted = 0;
		for (i = 0; i < n; i++) {
			if (p[i].arrival <= time && p[i].remaining > 0) {
				anyProcessExecuted = 1;
				if (p[i].remaining <= time_quantum) {
					time += p[i].remaining;
					p[i].remaining = 0;
					completed++;
					p[i].completion = time;
					p[i].turnaround = time - p[i].arrival;
					p[i].waiting = p[i].turnaround - p[i].burst;
				} else {
					p[i].remaining -= time_quantum;
					time += time_quantum;
				}
			}
		}
		if (!anyProcessExecuted) {
			time++;
		}
	}

	printf("\nRound Robin:\nP\tWT\tTAT\n");
	for (i = 0; i < n; i++)
		printf("P%d\t%d\t%d\n", p[i].id, p[i].waiting, p[i].turnaround);
}

int main() {
	int n, time_quantum;
	Process p[MAX];

	printf("Enter number of processes: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		p[i].id = i + 1;
		printf("Enter arrival and burst time for P%d: ", p[i].id);
		scanf("%d %d", &p[i].arrival, &p[i].burst);
		p[i].remaining = p[i].burst;
	}

	printf("Enter Time Quantum: ");
	scanf("%d", &time_quantum);

	round_robin(p, n, time_quantum);

	return 0;
}

