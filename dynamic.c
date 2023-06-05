#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

unsigned int ask(void){
    unsigned int count ;
    printf("Gib die Länge ein!\n");
    scanf("%u", &count);
    return count;
}

int* make_array(unsigned int count){
    int* numbers = malloc(count * sizeof(int));

    for (unsigned int i= 0; i<count; i++){
        numbers[i]= (rand() % 100)+1;
    }
    return numbers;
}

void calculate(const int* numbers, unsigned int count, int* min, int* max, double* avg){
    *min= INT_MAX;
    *max = INT_MIN;
    *avg = 0;

    for(unsigned int i=0; i<count; i++){
        int num = numbers[i];

        if(num<*min){
            *min=num;
        }
        if(num>*max){
            *max=num;
        }
        *avg =*avg +num;
    }
    *avg/=count;
}

int main(void){
    int l;
    unsigned int count = ask();
    int* numbers = make_array(count);
    srand(time(NULL));
   

    int min, max;
    double avg;
    calculate(numbers, count, &min, &max, &avg);

    printf("Min: %d   Max:%d  average:%.3lf", min, max, avg);
    free(numbers);
    return 0;
}