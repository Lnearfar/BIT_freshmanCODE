#include<stdio.h>
#define SIDELEN 100
int flr[SIDELEN][SIDELEN];
int count=1;
int N;
/*floor from start to end,and puts count in it,L for all*/

void flooring(int*,int,int);

int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)//floor左上半边
    {
        int L=i;
        if(i%2!=0) flooring(&flr[i-1][0],L,1);
        else flooring(&flr[0][i-1],L,0);
    }
    for(int i=N+1;i<=2*N-1;i++)//floor右下半边
    {
        int L=2*N-i;
        if(i%2!=0) flooring(&flr[N-1][i-N],L,1);
        else flooring(&flr[i-N][N-1],L,0);
    }
    for(int i=0;i<=N-1;i++)
    {
        for(int j=0;j<=N-1;j++)
        {
            if(j==0) printf("%2d",flr[i][j]);
            else printf("%3d",flr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void flooring(int *start,int L,int judge)
{
    if(judge)//from leftdown to rightup(judge==1)
    {
        for(int i=0;i<L;i++)
        {
            *(start-i*(SIDELEN-1))=count++;
        }
    }
    else//from rightup to left down(judge==0)
    {
        for(int i=0;i<L;i++)
        {
            *(start+i*(SIDELEN-1))=count++;
        }
    }
}