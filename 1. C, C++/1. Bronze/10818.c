#include <stdio.h>

int main(void) {
    int N, temp, max = -1000001, min = 1000001;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        if (temp >= max)
            max = temp;
        if (temp <= min)
            min = temp;
    }

    printf("%d %d", min, max);
}