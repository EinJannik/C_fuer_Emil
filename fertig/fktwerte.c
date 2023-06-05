#include<stdio.h>
#include<math.h>

void wert(int anzahl)
{
    float diff;
    diff = 1.0/anzahl;
    for(int i=0; i<anzahl; i++)
    {
        printf("%0.3f    %0.3f\n", diff*i, 0.5*pow(diff*i,3));
    }
}

int main(void)
{
    int zahl;
    printf("Gib die Anzahl der stellen ein!\n");
    scanf("%d", &zahl);
    wert(zahl);
    return 0;
}