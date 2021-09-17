#include <stdio.h>
int hansu(int N);

int main(void) {
	int N, count;
	count = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		if (hansu(i) == 'T')
			count += 1;
	}

	printf("%d", count);
}

int hansu(int N) {
	int temp = N;
	char TF = 'T';
	int n1, n2, n3;

	for (; temp >= 100; temp /= 10) {
		n1 = temp % 10;
		n2 = (temp % 100) / 10;
		n3 = (temp % 1000) / 100;

		if ((n1 - n2) != (n2 - n3)) {
			TF = 'F';
			break;
		}
	}

	return TF;
}