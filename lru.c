#include <stdio.h>

int main() {
	int n, nf, pages[100], frames[10], pgf=0;

	printf("Enter number of pages: ");
	scanf("%d", &n);

	printf("Enter page sequence: ");
	for(int i=0; i<n; i++) {
		scanf("%d", &pages[i]);
	}

	printf("Enter number  of frames: ");
	scanf("%d", &nf);

	for(int i=0; i<nf; i++) {
		frames[i]=-1;
	}

	for(int i=0; i<n; i++) {
		int hit=0;

		for(int j=0; j<nf; j++) {
			if(pages[i]==frames[j]) {
				hit=1;
				break;
			}
		}

		if(hit==0) {
			int lru=9999, index=-1;

			for(int j=0; j<nf; j++) {
				int lu=-1;
				for(int k=i-1; k>=0; k--) {
					if(frames[j]==pages[k]) {
						lu=k;
						break;
					}
				}

				if(lu<lru) {
					lru=lu;
					index=j;
				}
			}

			frames[index]=pages[i];
			pgf++;
		}

		for(int j=0; j<nf; j++) {
			printf("%d ", frames[j]);
		}

		printf("\n");
	}

	printf("Total page faults using LRU: %d\n", pgf);
	return 0;
}
