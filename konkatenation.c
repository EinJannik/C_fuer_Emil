#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENG 50
#define FORMAT_STR "%50s"

size_t my_strlen(const char* str){
    const char* start = str;
    for(; *str;str++){

    }
    return str-start;
}

void my_memcpy(char* dst, const char* src, size_t len){
    for(size_t i= 0; i<len; i++){
        dst[i]= src[i];
    }
}

char* concat(const char* str1, const char* str2){
    size_t len1 = my_strlen(str1);
    size_t len2 = my_strlen(str2);


    size_t len = len1 +1 + len2 +1;
    char* str = malloc(len*sizeof(char));

    my_memcpy(&str[0], str1, len1);
    str[len1]=' ';
    my_memcpy(&str[len1 +1], str2, len2);
    str[len-1]='\0';
    return str;
}

int main(void){
    char wort1[MAX_LENG+1];
    char wort2[MAX_LENG+1];
    printf("Gib Wort1 ein!\n");
    scanf(FORMAT_STR, &wort1);
    printf("Gib Wort2 ein!\n");
    scanf(FORMAT_STR, &wort2);

    char* str = concat(wort1, wort2);
    printf("Verbundener string: \"%s\" \n", str);

    free(str);


    return 0;
}

