#include<stdio.h>

int main(void){
    float x;
    float y;
    printf("Gib Zahl x ein!");
    scanf("%f", &x);
    y=0.5*(2+x);
    printf("Dein Ergebnis ist %f", y);
    return 0;
}