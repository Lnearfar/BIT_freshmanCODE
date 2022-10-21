#include <stdio.h>
#include <math.h>
#include <string.h>

float x, y;

void transform(char s, float w, float l)
{
    if (s == 'R')
    {
        x = 2 * w - x;
    }
    else if (s == 'L')
    {
        x = -x;
    }
    else if (s == 'F')
    {
        y = -y;
    }
    else //s=="B"
    {
        y = 2 * l - y;
    }
}

int main()
{
    float w, l, x0, y0, x1, y1;
    scanf("%f%f%f%f%f%f", &w, &l, &x0, &y0, &x1, &y1);
    getchar();
    char Line[1001];
    gets(Line);
    int k = strlen(Line);
    x = x0;
    y = y0;
    for (int i = 0; i < k; i++)
    {
        transform(Line[i], w, l);
    }
    double L = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
    printf("%.4lf\n", L);
    return 0;
}