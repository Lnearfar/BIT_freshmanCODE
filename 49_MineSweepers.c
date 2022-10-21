#include<stdio.h>
char map[102][102];
int minenum(int i,int j)
{
    int count=0;
    if(map[i-1][j-1]=='*') count++;
    if(map[i-1][j]=='*') count++;
    if(map[i-1][j+1]=='*') count++;
    if(map[i][j-1]=='*') count++;
    if(map[i][j+1]=='*') count++;
    if(map[i+1][j-1]=='*') count++;
    if(map[i+1][j]=='*') count++;
    if(map[i+1][j+1]=='*') count++;
    return count;
}
int main()
{
    int m,n,X=0,minenum();
    while(scanf("%d%d",&n,&m))
    {
        if(n==0||m==0) return 0;
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                map[i][j]=getchar();
            }
            getchar();
        }
        for(int j=0;j<=m+1;j++) {if(map[0][j]!='.') map[0][j]='.';}
        for(int j=0;j<=m+1;j++) {if(map[n+1][j]!='.') map[n+1][j]='.';}
        for(int i=0;i<=n+1;i++) {if(map[i][0]!='.') map[i][0]='.';}
        for(int i=0;i<=n+1;i++) {if(map[i][m+1]!='.') map[i][m+1]='.';}

        if(X!=0) printf("\n");
        printf("Field #%d:\n",++X);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(map[i][j]=='*') printf("*");
                else printf("%d",minenum(i,j));
            }
            printf("\n");
        }
    }
    return 0;
}