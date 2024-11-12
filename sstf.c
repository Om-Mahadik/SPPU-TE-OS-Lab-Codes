#include <stdio.h>
#include <stdlib.h>

int main() {
	int requests[100];
	int n, start;
	int thm = 0;
	int count = 0;
	int i, minD, index;

	printf("Enter the number of total request: ");
	scanf("%d", &n);

	printf("Enter the request sequence: ");
	for(i=0; i<n; i++) {
		scanf("%d", &requests[i]);
	}

	printf("Enter the initail head position: ");
	scanf("%d", &start);

	while(count!=n) {
		minD = 1000;

		for(i=0; i<n; i++) {
			int distance = abs(requests[i]-start);

			if(distance < minD) {
				minD = distance;
				index=i;
			}
		}

		start = requests[index];
		thm += minD;

		requests[index] = 1000;
		count++;
	}

	printf("Total Head Movement is %d\n", thm);

	return 0;
}
