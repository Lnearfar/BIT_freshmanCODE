#include<stdio.h>
int main()
{
    int n,i,j;
    char pizza;
    scanf("%d",&n);
    getchar();
    pizza=getchar();
    for(i=0;i<=n-1;i++)
    {
        if(i==0||i==n-1)
        {
            printf("#");
            for(int j=1;j<=n-2;j++) printf("-");
            printf("#\n");
        }
        else
        {
            if(i==1||i==n-2)
            {
                printf("|");
                for(int j=1;j<=(n-3)/2;j++)
                printf("*-");
                printf("*|\n");
            }
            else
            {
                if(i%2==0) 
                {
                    printf("||");
                    for(int j=1;j<=n-4;j++) printf("%c",pizza);
                    printf("||\n");
                }
                else
                {
                    printf("|*");
                    for(int j=1;j<=n-4;j++) printf("%c",pizza);
                    printf("*|\n");
                }
            }
        }
    }
    return 0;
}