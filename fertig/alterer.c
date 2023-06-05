#include<stdio.h>

int main(void){
    int gebjahr;
    int alter;
    printf("Wann wurdest du geboren? ");
    scanf("%d", &gebjahr);
    alter=2022-gebjahr;
    printf("Sie sind oder werden dieses Jahr %d Jahre alt", alter);
    return 0;

}