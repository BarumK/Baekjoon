#include <stdio.h>

int main(void) {
    int N, X, temp;
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        if (temp < X) {
            printf("%d ", temp);
        }
    }
}