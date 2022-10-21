#include <string.h>
#include <stdio.h>
int main()
{
    char a[500], b[500];
    int c[500];
    int i, j, k, n, p, K, len, flag, d, bi, J, I; // n为几个算式，p为符号;
    scanf("%d", &n);
    for (d = 1; d <= n; d++)
    {
        scanf("%s", &a);
        len = strlen(a);
        for (j = 0; j < len; j++)
            if (a[j] == '+' || a[j] == '-')
                break;
        p = j;                                    // 符号所处位置；
        for (j = p + 1, i = 0; j < len; j++, i++) // b[0]开始是首位
            b[i] = a[j] - '0';
        I = i--; // b[0]--b[I]
        for (j = 0; j < p; j++)
            a[j] = a[j] - '0';
        J = j--;         // a[0]-a[J]
        k = 0;           // aj 、a[0]开始是首位；求和转化
        if (a[p] == '+') //高精度加法处理
        {
            while (i != -1 && j != -1)
            {
                c[k] = a[j] + b[i];
                k++, i--, j--;
            }
            if (i >= 0)
            {
                while (i > -1)
                    c[k] = b[i],
                    i--, k++;
            }
            if (j >= 0)
            {
                while (j > -1)
                    c[k] = a[j], j--, k++;
            }
            c[k] = 0;                /* 很重要的啊 */
            K = k;                   // c[0]是个位
            for (k = 0; k <= K; k++) //进位
            {
                if (c[k] >= 10)
                {
                    c[k] = c[k] % 10;
                    c[k + 1] = c[k + 1] + 1;
                }
            }
            if (c[K] != 0)
                printf("%d", c[K]);
            for (k = K - 1; k >= 0; k--)
                printf("%d", c[k]);
            printf("\n");
        }
        if (a[p] == '-') // flag=0,a-b,a>=b;flag=1,b-a,b>a
        {
            if (p > len - p - 1)
                flag = 0; // a位数多 ,公式不对吗？！！
            if (p < len - p - 1)
                flag = 1;         // b位数多
            if (p == len - p - 1) //你的else出了什么状况？？
            {
                a[p] = 0;
                b[I + 1] = 0; //给b加终止符啊！
                bi = strcmp(a, b);
                if (bi > 0)
                    flag = 0;
                if (bi == 0)
                {
                    printf("0\n");
                    flag = -1;
                } //没出效果，输出了符号
                if (bi < 0)
                    flag = 1;
            }
            if (flag == 0)
            {
                while (i != -1 && j != -1)
                {
                    c[k] = a[j] - b[i];
                    k++, i--, j--;
                }
                if (j >= 0)
                {
                    while (j > -1)
                        c[k] = a[j],
                        j--, k++;
                }
                K = k - 1;               // c[0]是个位 ,c[K]是首位
                for (k = 0; k <= K; k++) //退位
                {
                    if (c[k] < 0)
                    {
                        c[k] = c[k] + 10;
                        c[k + 1] = c[k + 1] - 1;
                    }
                }
                for (k = K; c[k] == 0; k--)
                {
                }
                for (; k >= 0; k--)
                    printf("%d", c[k]);
                printf("\n");
            }
            if (flag == 1)
            {
                while (i != -1 && j != -1)
                {
                    c[k] = b[i] - a[j];
                    k++, i--, j--;
                }
                if (i >= 0)
                {
                    while (i > -1)
                        c[k] = b[i], i--, k++;
                }
                K = k - 1;               // c[0]是个位 ,c[K]是首位
                for (k = 0; k <= K; k++) //退位
                {
                    if (c[k] < 0)
                    {
                        c[k] = c[k] + 10;
                        c[k + 1] = c[k + 1] - 1;
                    }
                }
                for (k = K; c[k] == 0; k--)
                {
                }
                printf("-");
                for (; k >= 0; k--)
                    printf("%d", c[k]);
                printf("\n");
            }
        }
    }
    return 0;
}