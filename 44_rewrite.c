#include "stdio.h"
#include "string.h"
int main()
{
    int N, i, j, p,cmp();
    char a[1000], b[1000], c[500];
    scanf("%d", &N);
    for (int k = 0; k < N; k++)
    {
        scanf("%s", &a);
        for (p = 0; a[p] != '+' && a[p] != '-'; p++)
            ; //找到符号在a中的下表p
        for (i = p + 1; i <= strlen(a) - 1; i++)
        {
            b[i - (p + 1)] = a[i];
        }
        b[i-p-1]='\0';
        if (a[p] == '+') //算加法
        {
            i = 0;
            int l1 = p, l2 = strlen(b);
            while (l1 >= 1 && l2 >= 1)
            {
                c[i] = a[l1 - 1] + b[l2 - 1] - 48;
                i++;
                l1--;
                l2--;
            }
            while(l1 > 0)
            {
                c[i] = a[l1 - 1];
                i++;
                l1--;
            }
            while(l2 > 0)
            {
                c[i] = b[l2 - 1];
                i++;
                l2--;
            }
            c[i] = '0';
            for (j = 0; j <= i - 1; j++) //进位
            {
                if (c[j] - 48 > 9)
                {
                    c[j] = c[j] - 10;
                    c[j + 1]++;
                }
            }
            if (c[i] == '0')
            {
                for (j = i - 1; j >= 0; j--)
                    printf("%c", c[j]);
                printf("\n");
            }
            else
            {
                for (j = i; j >= 0; j--)
                    printf("%c", c[j]);
                printf("\n");
            }
        }
        else //算减法
        {
            i = 0;
            int l1 = p, l2 = strlen(b);
            a[p]='\0';
            if (cmp(a, b) == 0)//两数相等
            {
                printf("0\n");
            }
            else if (cmp(a, b)==1)//a>b
            {
                while (l1 >= 1 && l2 >= 1)
                {
                    c[i] = a[l1 - 1] - b[l2 - 1] +48;
                    i++;
                    l1--;
                    l2--;
                }
                while(l1 >= 1)
                {
                    c[i] = a[l1 - 1];
                    i++;
                    l1--;
                }
                for (j = 0; j <= i - 1; j++) //借位
                {
                    if (c[j] - 48 < 0)
                    {
                        c[j] = c[j] + 10;
                        c[j + 1]--;
                    }
                }
                for (; c[i-1] == '0'; i--);
                for (j = i - 1; j >= 0; j--)
                printf("%c", c[j]);
                printf("\n");
            }
            else//a<b
            {
                while (l1 >= 1)
                {
                    c[i] = b[l2 - 1] - a[l1 - 1] +48;
                    i++;
                    l1--;
                    l2--;
                }
                while(l2 >= 1)
                {
                    c[i] = b[l2 - 1];
                    i++;
                    l2--;
                }
                for (j = 0; j <= i - 1; j++) //借位
                {
                    if (c[j] - 48 < 0)
                    {
                        c[j] = c[j] + 10;
                        c[j + 1]--;
                    }
                }
                for (; c[i-1] == '0'; i--);
                printf("-");
                for (j = i - 1; j >= 0; j--)
                printf("%c", c[j]);
                printf("\n");
                
            }
        }
    }
    return 0;
}
int cmp(char *p,char *q)
{
    int lp=strlen(p),lq=strlen(q);
    int c=(lp>lq)?1:((lp<lq)?-1:(strcmp(p,q)>0?1:(strcmp(p,q)<0?-1:0)));
    return c;
}