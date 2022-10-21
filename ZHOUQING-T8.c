#include <stdio.h>
float Maxv = 0;
float w[3], v[3];

float max(float x, float y)
{
    return x > y ? x : y;
}

float MaxValue(int n, float W)
{
    if (n == 0)
    {
        return 0;
    }
    else if (W >= w[n - 1])
    {
        return max(MaxValue(n - 1, W), MaxValue(n - 1, W - w[n - 1]) + v[n - 1]);
    }
    else
        return MaxValue(n - 1, W);
}
int main()
{

    for (int i = 0; i < 3; i++)
    {
        scanf("%f", &w[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        scanf("%f", &v[i]);
    }
    printf("MaxValue=%.1f\n", MaxValue(3, 10));
    return 0;
}