#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d",&n);
    if(n%8!=0)
    {
        printf("No change.\n");
    }
    else
    {
        k=5*n/8;
        printf("%d,%d,%d\n",10*k,12*k,9*k);
    }
}