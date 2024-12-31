#include <stdio.h>
int new_num(int n);

int main(void) {
    int N;
    int count = 0;
    scanf("%d", &N);
    int temp = N;

    while (((count != 0) && (temp != N)) || (count == 0)) {
        temp = new_num(temp);
        count++;
    }
    printf("%d", count);
}

int new_num(int n) {
    if (n < 10) {
        return 10 * n + n;
    }
    else {
        return (n % 10) * 10 + (n / 10 + n % 10) % 10;
    }
}