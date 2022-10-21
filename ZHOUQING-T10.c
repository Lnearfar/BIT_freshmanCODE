#include <stdio.h>

int raw(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 'a';
    }
    else
        return 'A';
}
int main()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    for (int line = 1; line <= n; line++)
    {
        int i;
        if (line <= (n + 1) / 2 - 1)
        //aaaaaa  aaaaa
        //abbbba  abbba
        //abccba  abcba
        //abccba  abcba
        {
            for (i = 0; i < line; i++)
            {
                printf("%c", (c - raw(c) + i) % 26 + raw(c));
            }
            i--;
            for (int j = 0; j < n - 2 * line; j++)
            {
                printf("%c", (c - raw(c) + i) % 26 + raw(c));
            }

            for (i = line - 1; i >= 0; i--)
            {
                printf("%c", (c - raw(c) + i) % 26 + raw(c));
            }
        }
        else
        {
            for (i = 0; i < (n + 1) / 2; i++)
            {
                printf("%c", (c - raw(c) + i) % 26 + raw(c));
            }
            for (i = (n) / 2 - 1; i >= 0; i--)
            {
                printf("%c", (c - raw(c) + i) % 26 + raw(c));
            }
        }
        printf("\n");
    }
    return 0;
}