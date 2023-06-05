#include<stdio.h>

unsigned int reksum(unsigned int n){
    switch(n){
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return (n+reksum(n-1));
    }
}

void main(void){
    unsigned int m;
    printf("Gib n ein!\n");
    scanf("%u", &m);
    printf("Die Summe der ersten %u Zahlen ist: %u\n", m, reksum(m));
    return;
}