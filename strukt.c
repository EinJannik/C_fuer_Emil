#include <stdio.h>
#include <string.h>
struct namestruct{
    char vorname[20];
    char nachname[20];
};

int ausgabe(struct namestruct* namo){
    printf("Hallo, %s %s!\n", (*namo).vorname, namo->nachname);
    return 0;
}

int ausgabe2(struct namestruct namo){
    printf("Hallo, %s %s!\n", namo.vorname, namo.nachname);
    return 0;
}

int main(void){
    
    struct namestruct name;

    printf("Gib deinen Vornamen ein!\n");
    scanf("%s", name.vorname);
    printf("Gib deinen Nachnamen ein!\n");
    scanf("%s", name.nachname);
    ausgabe(&name);
    ausgabe2(name);
    return 0;
}