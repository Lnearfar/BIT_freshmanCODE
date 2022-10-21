#include <stdio.h>
#include <string.h>
int main()
{
    long int BASE();
    int MAX();
    char M[100], N[100];
    int i, j, signal;
    scanf("%s%s", M, N);
    signal = 0;
    if (MAX(M) == MAX(N) && MAX(M) == 0)
    {
        printf("%s (base 2) = %s (base 2)\n", M, N);
        return 0;
    }
    for (i = MAX(M) + 1; signal == 0 && i <= 36; i++)
    {
        for (j = MAX(N) + 1; j <= 36; j++)
        {
            if (BASE(M, i) == BASE(N, j))
            {
                printf("%s (base %d) = %s (base %d)\n", M, i, N, j);
                signal = 1;
                break;
            }
        }
    }
    if (signal == 0)
    {
        printf("%s is not equal to %s in any base 2..36\n", M, N);
    }
    return 0;
}
long int BASE(char B[100], int k) /*to calculate B in base k to base 10*/
{
    int A[100], i, j;
    long int temp, M = 0;
    int L = strlen(B);
    for (i = 0; i < L; i++)
    {
        if (B[i] >= 65)
            A[i] = B[i] - 55;
        if (B[i] <= 57)
            A[i] = B[i] - 48;
    }
    for (i = 0; i <= L - 1; i++)
    {
        temp = A[i];
        for (j = 0; j < L - 1 - i; j++)
        {
            temp *= k;
        }
        M += temp;
    }
    return M;
}
int MAX(char B[100])
{
    int L = strlen(B), i, m = 0;
    for (i = 0; i <= L - 1; i++)
    {
        if (m < B[i])
            m = B[i];
    }
    if (m >= 65)
    {
        return (m - 55);
    }
    else
    {
        return (m - 48);
    }
}