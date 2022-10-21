/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 4

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int resort(int (*pa)[COL], int row, int col)
{
    for (int k = 0; k < ROW; k++)
    {
        for(int i=COL-1;i>=1;i--)
        {
            int max=0;
            for(int j=1;j<=i;j++)
            {
                if(pa[k][max]<pa[k][j])
                {
                    max=j; 
                }
            }
            if(max!=i)
            {
                int temp=pa[k][max];
                pa[k][max]=pa[k][i];
                pa[k][i]=temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{

    int a[ROW][COL];
    //    int num;

    int(*pa)[COL];

    int i = 0, j = 0;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
            scanf("%d", &a[i][j]);
    }
    pa = a;

    resort(a, ROW, COL);

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    return 0;
}