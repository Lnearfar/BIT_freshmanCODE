#include <stdio.h>
#include <string.h>
#define STRLEN 1000

int cmp(char *q, char *stemp, int l)
{
    for (int i = 0; i < l; i++)
    {
        if (q[i] != stemp[i])
            return 1;
    }
    return 0;
}

void cpy(char *p, char *stemp, int l)
{
    for (int i = 0; i < l; i++)
    {
        stemp[i] = p[i];
    }
    stemp[l] = '\0';
}

int main()
{
    char s[STRLEN], stemp[STRLEN];
    scanf("%s", s);
    int l = 2, length = 0, L = strlen(s), count = 1;
    char *p, *pmax = NULL;

    for (l = 2; l <= strlen(s)/2+1; l++)
    {
        for (p = s; p <= s + L - l; p++) //p,p+1,...p+l-1 is the pattern
        {
            cpy(p, stemp, l);
            int tempcount = 0;
            for (char *q = s; q <= s + L - l; q++)
            {
                if (cmp(q, stemp, l) == 0)
                {
                    tempcount++;
                    q+=l-1;
                }
            }
            if (tempcount >= count)
            {
                if (tempcount > count)
                {
                    count = tempcount;
                    pmax = p;
                    length = l;
                }
                else if (tempcount == count && l > length)
                {
                    pmax = p;
                    length = l;
                }
                else
                    continue;
            }
        }
    }
    if (count == 1)
    {
        printf("no result!\n");
    }
    else
    {
        cpy(pmax, stemp, length);
        printf("%s %d times\n", stemp, count);
    }
    return 0;
}