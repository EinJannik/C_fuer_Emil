#include<stdio.h>

void nat1 (unsigned int n){
    unsigned int i=0;
    while(i<=n){
        printf("%u\n", i);
        i++;
    }

}

void nat2 (unsigned int n){
    unsigned int i=0;
    do{
        printf("%u\n", i);
        i++;
    }while(i<=n);
}

void nat3 (unsigned int n) {
    for(unsigned int i=0; i<=n; i++){
        printf("%u\n", i);
    }
}



void main(void){
    unsigned int m;
    int v;
    printf("Gib n ein\n");
    scanf("%u", &m);
    printf("[1] while, [2] while do, [3] for\n");
    scanf("%i", &v);
    printf("\n\n");
    switch(v){
        case 1:
            nat1(m);
            break;
        case 2:
            nat2(m);
            break;
        case 3:
            nat3(m);
            break;
        default: 
            printf("falsche Eingabe\n");
    }
    return;
}