#include <stdio.h>

int main(void) {
	int N1, N2, count, ave;
	scanf("%d", &N1);

	for (int i = 0; i < N1; i++) {
	    scanf("%d", &N2);
	    int arr[N2];
		ave = 0;
		count = 0;

		for (int j = 0; j < N2; j++) {
			scanf("%d", &arr[j]);
			ave += arr[j];
		}

		for (int j = 0; j < N2; j++) {
			if (arr[j] * N2 > ave)
				count++;
		}
		printf("%.3f%\n", ((float)count / (float)N2) * 100);
	}
}