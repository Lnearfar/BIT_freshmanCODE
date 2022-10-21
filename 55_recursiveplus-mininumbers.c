#include<stdio.h>
int cstplus(int ,int );
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("The sum from %d to %d is %d.\n",n,m,cstplus(n,m));
    return 0;
}
int cstplus(int n,int m)
{
    if(n==m) return m;
    else
    {
        return n+cstplus(n+1,m);
    }
}
