#include <stdio.h>

int main() {
	int n, nf, pages[100], frames[10], pgf=0, pos=0;

	printf("Enter the number of pages: ");
	scanf("%d", &n);

	printf("Enter the page reference sequence: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &pages[i]);
	}

	printf("Ener the number of frames: ");
	scanf("%d", &nf);

	for(int i=0; i<nf; i++) {
		frames[i]=-1;
	}

	for(int i=0; i<n; i++) {
		int hit=0;

		for(int j=0; j<nf; j++) {
			if(frames[j]==pages[i]) {
				hit=1;
				break;
			}
		}

		if(hit==0) {
			frames[pos]=pages[i];
			pos=(pos+1)%nf;
			pgf++;
		}

		for(int j=0; j<nf; j++) {
			printf("%d ", frames[j]);
		}
		printf("\n");
	}

	printf("totak page faults using FCFS: %d\n", pgf);
	return 0;
}
