#include<stdio.h>
int main()
{
    int arr[100][100],circle,number=0,i,j,n,c;
    scanf("%d",&n);
    circle=(n+1)/2;
    for(c=1;c<=circle;c++)
    {
        if(c-1==n-c)
        {
            number++;
            arr[c-1][c-1]=number;
            break;
        }
        else/*input all numbers from 1 to n*n*/
        {
            for(i=c-1;i<=n-c;i++)
            {
                number++;
                arr[c-1][i]=number;
            }
            for(i=c;i<=n-c;i++)
            {
                number++;
                arr[i][n-c]=number;
            }
            for(i=n-c-1;i>=c-1;i--)
            {
                number++;
                arr[n-c][i]=number;
            }
            for(i=n-c-1;i>=c;i--)
            {
                number++;
                arr[i][c-1]=number;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%3d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}