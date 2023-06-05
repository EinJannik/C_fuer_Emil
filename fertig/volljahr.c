#include<stdio.h>

int volljahr(int alter){
    if(alter>=18){
        return 1;
    }else{
        return 0;
    }
}

void main(void){
    int alter;
    printf("Gib dein Alter ein!\n");
    scanf("%d", &alter);
    if (volljahr(alter)){
        printf("Du bist volljährig.\n");
    }else{
        printf("Du bist minderjährig.\n");
    }
    return;
}