#include <stdio.h>
int addition(int c, int d);
int subtraktion(int c, int d);
int multiplikation(int c, int d);
int division(int c, int d);

int main(void)
{
    while(1){
    char rechenzeichen;
    int a,b, ergebnis;
    printf("Geben Sie eine zweistellige Rechenoperation ein.\n");
    scanf("%d %c %d", &a, &rechenzeichen, &b);
    switch(rechenzeichen){
        case '+':
            ergebnis=addition(a, b);
            break;
        case '-':
            ergebnis=subtraktion(a, b);
            break;
        case '*':
            ergebnis=multiplikation(a, b);
            break;
        case '/':
            ergebnis=division(a, b);
            break;
        default: 
            printf("Falsche Eingabe\n");   
            return 0;             
    }
    printf("%d%c%d=%d\n", a, rechenzeichen, b, ergebnis);
    }
    return 0;
} 

int addition(int c, int d){
    return (c+d);
}

int subtraktion(int c, int d){
    return (c-d);
}

int multiplikation(int c, int d){
    return (c*d);
}

int division(int c, int d){
    return (c/d);
}