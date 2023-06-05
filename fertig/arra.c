#include<stdio.h>

int main(void){
    int arr[3], a, b, c;
    printf("a: %p b: %p c: %p arr: %p %p %p", &a, &b, &c, &arr[0], &arr[1], &arr[2]);
    return 0;
}