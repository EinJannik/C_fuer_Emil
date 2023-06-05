#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    unsigned int playernumber, AInumber;
    time_t t;
    srand((unsigned) time(&t));
    AInumber=((rand() % 100)+1);
    printf("Gib eine Zahl aus dem Intervall [1;100] ein!\n");
    while(1)
    {
        scanf("%u", &playernumber);
        if(playernumber == AInumber)
        {
            printf("Du hattest Glück!\n");
            break;
        }else
        {
            printf("Du hattest Pech :) \n");
        }
    }
    return 0;
}