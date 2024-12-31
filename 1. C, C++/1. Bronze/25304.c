// 25304
#include <stdio.h>

int main() {
    int total, num, a, b;
    scanf("%d", &total);
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d %d", &a, &b);
        total -= a * b;
    }
    if(total == 0) printf("Yes");
    else printf("No");
}