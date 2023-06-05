#include<stdio.h>
#include<math.h>

float fläche(float rad){
    return(M_PI*rad*rad);
}

float umfang(float rad){
    return(M_PI*2.0*rad);
}

void main(void){
    float r;
    printf("Gib den Radius ein!(m)\n");
    scanf("%f", &r);
    printf("Fläche: %f m\n", fläche(r));
    printf("Umfang: %f m\n", umfang(r));
    return;
}