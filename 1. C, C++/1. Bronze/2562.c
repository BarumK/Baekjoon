#include <stdio.h>

int main(void) {
    int N, temp, max = -1;
    
    for (int i = 1; i <= 9; i++) {
        scanf("%d", &temp);
        if (temp > max) {
            max = temp;
            N = i;
        }
    }
    printf("%d\n%d", max, N);
}