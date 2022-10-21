#include<stdio.h>
void sort(int N,int *p)
{
    for(int i=N-1;i>=1;i--)
    {
        int *max=p;
        for(int j=1;j<=i;j++)//由小到大排序
        {
            if(*max<*(p+j))
            {
                max=p+j;
            }
        }
        int temp=*max;//exchage p+i and max
            *max=*(p+i);
            *(p+i)=temp;
    }
}
int main()
{
    void sort(int,int *);
    int n,m,d[100],h[100],score=0;//nmdh
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&d[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&h[i]);
    }
    sort(n,&d[0]);
    sort(m,&h[0]);
    int i=0,j=0;
    for(j=0;j<=n-1&&i<=m-1;j++)
    {
        while(h[i]<d[j]&&i<=m-1) i++;
        if (i <= m-1)
        {
            score += h[i];
            i++;
        }
        else 
        {
            printf("bit is doomed!\n");
            return 0;
        }
    }
    if(j==n) printf("%d\n",score);
    else printf("bit is doomed!\n");
    return 0;
}