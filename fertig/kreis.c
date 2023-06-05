#include<stdio.h>
#include<math.h>

int main(void){

    float r;
    int k;
    printf("Gib den Radius ein!(m)\n");
    scanf("%f", &r);
    printf("Kreisberechnung (1) oder Kugelberechnung (2)?\n");
    scanf("%d", &k);
    
    if (k==1){
        printf("Die Fläche beträgt %f m²\n\n", (M_PI*pow(r,2.0)) );
        printf("Der Umfang beträgt %f m\n", (2.0*M_PI*r));
    }else if(k==2){
        printf("Die Oberfläche beträgt %f m²\n\n", 4.0*M_PI*pow(r,2));
        printf("Das Volumen beträgt %f m³\n",4.0/3*M_PI*pow(r,3));

    }else{printf("ungültige Eingabe");

    };
    return 0;
}