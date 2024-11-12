#include <stdio.h>

int main() {
	int n, nf, pages[100], frames[10], pgfaultcnt = 0;

	printf("Enter the number of pages: ");
	scanf("%d", &n);
	printf("Enter the page reference sequence: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &pages[i]);
	printf("Enter the number of frames: ");
	scanf("%d", &nf);

	for (int i = 0; i < nf; i++)
		frames[i] = -1;

	for (int i = 0; i < n; i++) {
		int hit = 0;
		for (int j = 0; j < nf; j++) {
			if (frames[j] == pages[i]) {
				hit = 1;
				break;
			}
		}
		if (!hit) {
			int farthest = -1, index = -1;
			for (int j = 0; j < nf; j++) {
				int nextUse = 9999;
				for (int k = i + 1; k < n; k++) {
					if (frames[j] == pages[k]) {
						nextUse = k;
						break;
					}
				}
				if (nextUse > farthest) {
					farthest = nextUse;
					index = j;
				}
			}
			frames[index] = pages[i];
			pgfaultcnt++;
		}
	}

	printf("Total page faults: %d\n", pgfaultcnt);
	return 0;
}
