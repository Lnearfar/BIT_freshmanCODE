#include <stdio.h>
#include <string.h>
#define ERR 1000
int count[34];

int judge(char c)
{
    if (c >= 0 && c <= 32 || c == 127)
    {
        return c;
    }
    else
    {
        return ERR;
    }
}
int main()
{
    char ch;
    memset(count, 0, 34 * sizeof(int));
    while ((ch = getchar()) != EOF)
    {
        if (judge(ch) == 127)
        {
            count[33]++;
        }
        else if (judge(ch) <= 32)
        {
            count[judge(ch)]++;
        }
    }

    //output

    if (count[0] != 0)
    {
        printf("[0]=%d\n", count[0]);
    }
    for (int i = 1; i <= 33; i++)
    {
        if (count[i] != 0)
        {
            printf("[%d]=%d\n", i, count[i]);
        }
    }
    return 0;
}