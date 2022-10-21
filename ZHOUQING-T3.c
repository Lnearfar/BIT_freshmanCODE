#include<stdio.h>
int main()
{
    void pt(int,char);
    int n;
    char c,c0;
    scanf("%d %c",&n,&c);
    c0=c>96?'a':'A';
    for(int i=0;i<=n-1;i++)
    {
        pt(i,' ');
        if(i==n-1)
        {
            pt(1,(c+i-c0)%26+c0);
            printf("\n");
            return 0;
        }
        else
        {
            pt(1,(c+i-c0)%26+c0);
            pt(2*n-2*i-3,' ');
            pt(1,(c+2*n-2-i-c0)%26+c0);
            printf("\n");
        }
    }
    return 0;
}
void pt(int n,char c)
{
    for(int i=1;i<=n;i++) printf("%c",c);
}