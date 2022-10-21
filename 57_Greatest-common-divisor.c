#include<stdio.h>
int func(int a,int b)
{
    if(a%b==0) return b;
    else return func(b,a%b);
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d\n",func(m,n));
    return 0;
}