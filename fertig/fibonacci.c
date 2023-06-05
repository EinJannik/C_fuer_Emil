#include<stdio.h>

int fibo(int m){
    switch(m){
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return(fibo(m-1)+fibo(m-2));    
    }
}

int main(void){
    int n;
    printf("Gib n ein!\n");
    scanf("%i", &n );
    printf("%i", fibo(n));
    return 0;
}