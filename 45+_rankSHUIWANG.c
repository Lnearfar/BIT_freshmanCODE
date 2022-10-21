#include <stdio.h>
#include <string.h>
char Dictionary[124];
static struct imformation
{
    char name[21];
    char score[10000];
    int sign;
} people[1000];
int main()
{
    int N, i, j, cmp(); //结构数组初始化

    for(i=1;i<=26;i++)
    {
        Dictionary[64+i]=2*i-1;
        Dictionary[96+i]=2*i;
    }
    for(i=0;i<=9;i++)
    {
        Dictionary[48+i]=53+i;
    }
    Dictionary[123]='\0';
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s%s", &people[i].name, &people[i].score);
        people[i].sign = 1;
    }
    for (i = 0; i < N; i++) //进行比较输出
    {
        struct imformation *max, *p;
        p = &people[0];
        for (; (*p).sign == 0; p++);    //找到第一个需要比较的数
        max = p; //max初始化
        if (max == &people[0] + N - 1)
            printf("%s\n", (*max).name); //只剩一位
        else
        {
            p = max + 1;
            while (p <= &people[0] + N - 1)
            {
                for (; (*p).sign == 0 && p != (&people[0] + N - 1); p++); //???

                if (p == &people[0] + N - 1 && p->sign == 0)//如果p是最后一位且已经比较过了
                {
                    break;
                }
                else if (cmp(max->score, p->score) == 0) //发帖数相等，对名字比较
                {
                    for (j = 0; max->name[j] == p->name[j]; j++);

                    if (Dictionary[max->name[j]] > Dictionary[p->name[j]])//?????
                        max = p;
                }
                else if (cmp(max->score, p->score) < 0) max = p; //发帖数不等

                p++;
            }
            (*max).sign = 0;
            printf("%s\n", (*max).name);
        }
    }
    return 0;
}

int cmp(char *p, char *q)
{
    int lp = strlen(p), lq = strlen(q);
    int c = (lp > lq) ? 1 : ((lp < lq) ? -1 : (strcmp(p, q) > 0 ? 1 : (strcmp(p, q) < 0 ? -1 : 0)));
    return c;
}