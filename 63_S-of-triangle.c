#include <stdio.h>
#include <math.h>
#define InputNum 1000

int cod[InputNum][2];

float Striangle(int i, int j, int k)
{
    float s0 = fabs(cod[i][0] * cod[j][1] + cod[j][0] * cod[k][1] + cod[k][0] * cod[i][1] - cod[i][0] * cod[k][1] - cod[k][0] * cod[j][1] - cod[j][0] * cod[i][1]);
    return s0 / 2;
}

void solve()
{
    int n;
    float smax = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &cod[i][0], &cod[i][1]);
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (Striangle(i, j, k) > smax)
                {
                    smax = Striangle(i, j, k);
                }
            }
        }
    }
    printf("%.1f\n", smax);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        solve();
    }
    return 0;
}