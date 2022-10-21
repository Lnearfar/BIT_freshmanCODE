#include <stdio.h>
float plus(int n) //n>=2
{
    int m = (n % 2 == 0) ? 1 : -1;
    if (n == 1)
        return 1;
    else
        return plus(n - 1) + (float)m * 1 / n;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
        printf("1\n");
    else
    {
        printf("%.6f\n", plus(n));
    }
    return 0;
}