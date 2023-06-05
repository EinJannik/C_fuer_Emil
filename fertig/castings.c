#include<stdio.h>

int main(void){
    float a;
    int b;
    char c;
    printf("Gib eine Kommazahl ein!\n");
    scanf("%f", &a);
    b=a;
    c=a;
    printf("%f\n", a);
    printf("%d\n", b);
    printf("%lf\n", a);
    printf("%c\n", c);
    return 0;
}