#include <stdio.h>
#include <string.h>

int main(void) {
	int N, count, sum;
	char OX[80];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		sum = 0;
		count = 1;
		scanf("%s", OX);
		for (int j = 0; j < strlen(OX); j++) {
			if (OX[j] == 'O') {
				sum += count;
				count++;
			}
			else { // OX[j] == 'X'
				count = 1;
			}
		}
		printf("%d\n", sum);
	}
}