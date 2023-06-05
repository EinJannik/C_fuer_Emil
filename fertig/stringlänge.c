#include<stdio.h>

int stringlength(char* arr){
    int count= 0;
    for(int i=0; i<100; i++){
        printf("%c", arr[i]);
        if(arr[i]!=0){
            count++;
        }
    }
    return count;
}

int main(void){
    char kette[100] = { 0 };
    char string[] = "informatik";
    char s2[] = {'i', 'n', 'f', 'o', '\0'};
    char* s3 = "info";  //pointer auf ersten buchstaben
    for(int i=0; i<10; i++){
        kette[i]='a';
    };
    printf("\n%d\n", stringlength(kette));
    return 0;
}