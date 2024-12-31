#include <stdio.h>
int d(int n) {
	int sum = n;
	int temp = n;

	while (temp > 0) {
		sum += temp % 10;
		temp = temp / 10;
	}
	return sum;
}

int main(void) {
	int num[10001];
	for (int i = 0; i < 10001; i++)
		num[i] = i;

	for (int i = 1; i <= 10000; i++) {
		if (d(i) <= 10000)
			num[d(i)] = 0;
	}

	for (int i = 0; i < 10001; i++) {
		if (num[i] != 0)
			printf("%d\n", num[i]);
	}
}