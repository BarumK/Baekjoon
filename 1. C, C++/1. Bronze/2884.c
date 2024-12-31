#include <stdio.h>

int main(void) {
    int H, M;
    scanf("%d %d", &H, &M);

    M -= 45;

    if (M < 0) {
        H--;
        M += 60;
    }

    if (H < 0) {
        H = 23;
    }
    
    printf("%d %d", H, M);
}