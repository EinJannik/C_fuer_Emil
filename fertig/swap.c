#include<stdio.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
    return;
}

int main(void){
    int a, b;
    printf("Gib a und b ein!\n");
    scanf("%d %d", &a, &b);
    printf("vorher a: %d   b: %d\n", a, b);
    swap(&a, &b);
    printf("nachher a: %d   b:%d\n", a, b);
    return 0;
}