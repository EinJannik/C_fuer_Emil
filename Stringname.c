#include<stdio.h>

void invert(char* namo){
    for(int i=0; i<32; i++){
        switch(namo[i]){
            case 97 ... 122: //klein zu groß
                namo[i]=namo[i]-32;
                break;
            case 65 ... 90: //groß zu klein
                namo[i]=namo[i]+32;
                break;        
        }
    }
    return;
}

int main(void){
    char name[32] = { '\0' }; //Array initialisieren
    printf("Gib deinen Namen ein!\n");
    scanf("%s", &name); //Namen einlesen
    printf("\nDein Name ist %s\n", name);
    invert(name);
    printf("dEIN nAME iST %s\n", name);
    return 0;
}