#include <stdio.h>
#define ARRAY_INIT(array, size, value) {int i; for (i = 0; i < size; i++) { *(array + i) = value; }}

int main(void) {
	int arr1[10], arr2[42];
	ARRAY_INIT(arr2, 42, -1);
	int count = 0;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr1[i]);
		arr1[i] %= 42;
	}

	for (int i = 0; i < 10; i++) {
		arr2[arr1[i]] = 0;
	}

	for (int i = 0; i < 42; i++) {
		if (arr2[i] == 0)
			count++;
	}

	printf("%d\n", count);
}