#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void fuellen(int* array){
    for(int i=0; i<10; i++){
        array[i]= rand() % 100 +1;
    }
}

void sort(int* array){
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            if (array[j]<array[i]){
                int a = array[j];
                array[j] = array [i];
                array[i] = a;
            }
        }
    }
}

int main(void){
    time_t t;
    int array[10];
    srand((unsigned) time(&t));
    fuellen(array);
    for(int i=0; i<10; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
    sort(array);
    for(int i=0; i<10; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
    for(int i=9; i>=0; i--){
        printf("%d ", array[i]);
    }

    return 0;

}