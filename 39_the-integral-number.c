#include <stdio.h>
int main()
{
    int n, i, Ntemp, N = 1, k, signal, count = 0;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("%d\n", n);
    }
    else
    {
        for (i = 1; i <= n - 1; i++)
        {
            N *= 10;
        }
        for (i = N; i <= 10 * N - 1; i++) /*judge whether i is ok*/
        {
            Ntemp = i;
            if (Ntemp % (n * n) != 0)
                continue;
            else
            {
                signal = 1;
                for (k = 1; k <= n - 1; k++)
                {
                    Ntemp /= 10;
                    if (Ntemp % ((n - k) * (n - k)) != 0)
                    {
                        signal = 0;
                        break;
                    }
                }
                if (signal == 1)
                {
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}