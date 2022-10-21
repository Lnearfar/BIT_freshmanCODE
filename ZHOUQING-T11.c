#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int gettoken(char s[]);
int ati(char s[]);
void ita(int n, char s[]);

int main()
{
    char a[100];
    char b[100];
    int res, n;

    while ((res = gettoken(a)) != EOF)
    {
        if (res == 0)
        {
            n = ati(a);
            ita(n, b);
            puts(b);
        }
    }
}

int number(char *a) //judge whether a is a int
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] < '0' || a[i] > '9')
            return 0;
    }
    return 1;
}
int gettoken(char *a)
{
    memset(a, '\0', sizeof(char));
    int i = 0;
    for (i = 0;; i++)
    {
        a[i] = getchar();
        if (a[i] == EOF)
        {
            return EOF;
        }
        else if (isspace(a[i]))
        {
            a[i] = '\0';
            if (strlen(a) == 0)
            {
                return 1;
            }
            if (number(a))
            {
                return 0;
            }
            else
                return 1;
        }
    }
}

int ati(char *a)
{
    int L = strlen(a);
    int n = 0;
    for (int i = 0; i < L; i++)
    {
        n = 10 * n + a[i] - 48;
    }
    return n;
}

void reverse(char *pnum)
{
    int L = strlen(pnum);
    char *l = pnum, *r = pnum + L - 1;
    while (r > l)
    {
        char c = *l;
        *l = *r;
        *r = c;
        l++;
        r--;
    }
}

void ita(int n, char s[])
{
    int i;
    memset(s, '\0', sizeof(char));
    for (i = 0; n != 0; i++)
    {
        s[i] = n % 10 + 48;
        n /= 10;
    }
    s[i] = '\0';
    reverse(s);
}
