#include<stdio.h>

int main(void)
{
    int i =1234;
    for(int i=0; i<10; i++)
    {
        printf("zaehler: %i\n", i);
        int i= 78;
        printf("schleife: %i\n", i);
    }
    printf("main: %i\n", i);


    return 0;
}