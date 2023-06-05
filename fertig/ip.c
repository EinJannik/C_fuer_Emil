#include<stdio.h>

int main(void){
    long long ip=2886863399;
    int a,b,c,d;
    d=ip % 256;
    c=((ip-d) % 65536 )/256;
    b=((ip-d-c) % 16777216 )/65536;
    a=(ip -b-c-d)/16777216;
    printf("%d.%d.%d.%d",a,b,c,d);
    return 0;
}