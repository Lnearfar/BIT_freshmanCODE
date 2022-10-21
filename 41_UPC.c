#include<stdio.h>
int main()
{
    char a,b[6],c[6];
    scanf("%c%s%s",&a,b,c);
    int s1=a+b[1]+b[3]+c[0]+c[2]+c[4]-288;
    int s2=b[0]+b[2]+b[4]+c[1]+c[3]-240;
    int d=9-(3*s1+s2-1)%10;
    printf("%d\n",d);
    return 0;
}