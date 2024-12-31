#include <stdio.h>

int main(void) {
	int N, max;
	scanf("%d", &N);

	int arr1[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr1[i]);
		if ((i == 0) || (arr1[i] > max))
			max = arr1[i];
	}

	float arr2[N];
	float ave = 0;
	for (int i = 0; i < N; i++) {
		arr2[i] = ((float)arr1[i] / (float)max) * 100;
		ave += arr2[i];
	}

	printf("%f", ave / N);
}