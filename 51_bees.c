#include<stdio.h>
#include<string.h>
#define SIZE 100
#define STRLEN 100
char F[SIZE][STRLEN];
void plus(char* ,char*, int);
int main()
{
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    for(int i=0;i<=SIZE-1;i++)
    {
        for(int j=0;j<=STRLEN-1;j++)
        {
            F[i][j]='0';
        }
    }
    F[1][0]='1';F[1][1]='\0';
    F[2][0]='2';F[2][1]='\0';
    for(int i=3;i<=n2-n1;i++)
    {
        plus(F[i-1],F[i-2],i);
    }
    int L=strlen(F[n2-n1]);
    for(int i=L-1;i>=0;i--)
    {
        printf("%c",F[n2-n1][i]);
    }
    printf("\n");
    return 0;
}
/*大数加法计算a+b，把结果放入F[k]中*/
/*反向排序*/
void plus(char *a,char *b,int k)
{
    int i=0,j=0;
    while(*(a+i)!='\0'&&*(b+j)!='\0')
    {
        F[k][i]+=*(a+i)+*(b+j)-96;
        if(F[k][i]>=58)
        {
            F[k][i]-=10;
            F[k][i+1]++;
        }
        i++;j++;
    }
    if(*(a+i)=='\0')//b比较长
    {
        int t;
        for(t=j;*(b+t)!='\0';t++)
        {
            F[k][t]+=*(b+t)-48;
            if(F[k][t]>=58)
            {
            F[k][i]-=10;
            F[k][i+1]++;
            }
        }
        if(F[k][t]=='0') F[k][t]='\0';
        else F[k][t+1]='\0';
    }
    else //a比较长
    {
        int t;
        for(t=i;*(a+t)!='\0';t++)
        {
            F[k][t]+=*(a+t)-48;
            if(F[k][t]>=58)
            {
            F[k][i]-=10;
            F[k][i+1]++;
            }
        }
        if(F[k][t]=='0') F[k][t]='\0';
        else F[k][t+1]='\0';
    }

}
