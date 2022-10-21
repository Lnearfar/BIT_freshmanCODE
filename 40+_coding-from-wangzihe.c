#include <stdio.h>
#include <string.h>
int main()
{
    int N, i, total, f, H, h;
    char s[11], k;
    int c[27][27], m, n;

    for (n = 1; n < 27; n++)
    {
        c[n][1] = n;
        c[n][n] = 1;
        c[n][0] = 1;
    }

    for (n = 3; n < 27; n++)
    {
        for (m = 1; m < n; m++)
        {
            c[n][m] = c[n - 1][m] + c[n - 1][m - 1];
        }
    }

    scanf("%d", &H);

    for (h = 1; h <= H; h++)/*H arrs*/
    {
        total = 0;
        f = 1;
        for (i = 0; i <= N; i++)
        {
            s[i] = '\0';
        }

        scanf("%s", s);
        N = strlen(s);

        for (i = 1; i < N; i++)
        {
            if (s[i - 1] >= s[i])
            {
                f = 0;
                break;
            }
        }

        if (f == 0)
        {
            printf("0\n");
            continue;
        }

        else
        {

            for (i = N; i > 0; i--)
            {
                s[i] = s[i - 1];
            }

            for (i = 1; i < N; i++)
            {
                total += c[26][i];
            }

            for (i = 1; i <= N; i++)
            {
                if (i == 1)
                    k = 'a';
                else
                    k = s[i - 1] + 1;
                for (; k < s[i]; k++)
                {
                    total += c['z' - k][N - i];
                }
            }

            printf("%d\n", total + 1);
        }
    }
}
