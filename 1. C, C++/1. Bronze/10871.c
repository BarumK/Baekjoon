#include <stdio.h>

int main(void) {
    int N, X, temp;
    scanf("%d %d", &N, &X);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] < X) {
            printf("%d ", arr[i]);
        }
    }
}