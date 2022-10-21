#include<stdio.h>
#include<string.h>
int main()
{
    char a[50];
    int n,c,i,j,L;
    scanf("%s %c%d",a,&c,&n);
    if(a[1]=='\0')
    {
        a[1]='.';
        a[2]='\0';
    }
    L=strlen(a);
    for(j=L;j<=48;j++)
    {
        a[j]='0';
    }
    a[49]='\0';
    if(n>=0)/*n>=0*/
    {
        printf("%c",a[0]);
        for(i=2;i<=n+1;i++)
        {
            printf("%c",a[i]);
        }
        printf(".");
        for(i=2+n;i<=9+n;i++)
        {
            printf("%c",a[i]);
        }
        printf("\n");
    }
    else
    {
        int k=-n;
        if(k>=9)
        {
            printf("0.00000000\n");
        }
        else if(k==8)
        {
            printf("0.0000000%c\n",a[0]);
        }
        else
        {
            printf("0.");
            for(i=1;i<=k-1;i++)
            {
                printf("0");
            }
            printf("%c",a[0]);
            for(i=2;i<=9-k;i++)
            {
                printf("%c",a[i]);
            }
            printf("\n");
        }
    }
}
