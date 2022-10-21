#include<stdio.h>
int main()
{
    int n,i,j,first;
    scanf("%d%d",&n,&first);/*first is the first number*/
    if(n==1)
    {
        printf("%d\n",first);
        return 0;
    }
    for(j=1;j<=(3*n-1)/2;j++)
    {
        printf("%d ",(first+j-1)%10);
    }
    for(j=(3*n-2)/2;j>=2;j--)
    {
        printf("%d ",(first+j-1)%10);
    }
    printf("%d\n",first);
    for(i=2;i<=n-1;i++)/*output line 2 to n-1*/
    {
        for(j=1;j<=i-1;j++)
        {
            printf("  ");
        }
        printf("%d ",(first+i-1)%10);
        for(j=1;j<=3*n-2*i-2;j++)
        {
            printf("  ");
        }
        printf("%d\n",(first+i-1)%10);
    }
    for(j=1;j<=n-1;j++)/*out put the last line*/
    {
        printf("  ");
    }
    for(j=1;j<=(n+1)/2;j++)
    {
        printf("%d ",(first+n+j-2)%10);
    }
    for(j=n/2;j>=2;j--)
    {
        printf("%d ",(first+n+j-2)%10);
    }
    printf("%d\n",(first+n-1)%10);
    return 0;
}