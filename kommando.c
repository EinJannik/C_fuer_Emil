#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    printf("%s\n", argv[1]);
    
    int a= atoi((argv[1])); 
    printf("a: %d\n", a);
    int* arr1 = malloc(a*sizeof(int));
    for(int i=0; i<a;i++){
        arr1[i]=i+1;
        printf("%d\n", arr1[i]);
    }
    free(arr1);
    return 0;
}