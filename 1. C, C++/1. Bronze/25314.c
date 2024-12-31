// 25314
#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    while(1) {
        if(num <= 0) break;
        printf("long ");
        num -= 4;
    }
    printf("int");
}