#include <stdio.h>
#include <stdlib.h>
int rp[1001], RP;

int cmp(const void *p1, const void *p2)
{
    const int *a1 = (const int *)p1;
    const int *a2 = (const int *)p2;
    if (*a1 < *a2)
        return 1;
    else if (*a1 == *a2)
        return 0;
    else
        return -1;
}

int main()
{
    int N; //He will yingying N students.
    scanf("%d%d", &N, &RP);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &rp[i]);
    }

    qsort(rp, N, sizeof(int), cmp); // from greatest to least

    int count = 0, p, l;
    for (p = 0; rp[p] >= RP && p < N; p++)
        ;
    if (p == 0)
    {
        RP += N;
    }
    else //0 to p-1
    {
        for (l = p - 1; l >= 0; l--)
        {
            if (rp[l] >= RP)
            {
                RP += 2;
                count++;
            }
        }
        RP += N - count;
    }

    printf("%d\n", RP);
    return 0;
}