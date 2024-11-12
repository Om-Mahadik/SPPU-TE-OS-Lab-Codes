#include <stdio.h>
#define MAX 10

typedef struct {
	int id, arrival, burst, remaining, completion, waiting, turnaround;
	} Process;

void preemptive_sjf(Process p[], int n) {
	int time = 0, completed = 0, min_index, min_remaining;

	while (completed != n) {
		min_index = -1;
		min_remaining = 1e9;

		for (int i = 0; i < n; i++) {
			if (p[i].arrival <= time && p[i].remaining > 0 && p[i].remaining < min_remaining) {
				min_index = i;
				min_remaining = p[i].remaining;
			}
		}

		if (min_index == -1) {
			time++;
			continue;
		}

		p[min_index].remaining--;
		time++;

		if (p[min_index].remaining == 0) {
			completed++;
			p[min_index].completion = time;
			p[min_index].turnaround = time - p[min_index].arrival;
			p[min_index].waiting = p[min_index].turnaround - p[min_index].burst;
		}
	}

	printf("\nSJF (Preemptive):\nP\tWT\tTAT\n");
	for (int i = 0; i < n; i++) 
		printf("P%d\t%d\t%d\n", p[i].id, p[i].waiting, p[i].turnaround);
} 

int main() {
	int n;
	Process p[MAX];

	printf("Enter number of processes: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		p[i].id = i + 1;
		printf("Enter arrival and burst time for P%d: ", p[i].id);
		scanf("%d %d", &p[i].arrival, &p[i].burst);
		p[i].remaining = p[i].burst;
	}

	preemptive_sjf(p, n);

	return 0;
}

