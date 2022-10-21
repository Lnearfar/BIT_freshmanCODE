#include <stdio.h>
int main()
{
    int year, b, c, d, e;
    scanf("%d%d%d", &year, &b, &c);
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        int a[1][12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (b < 1 || b > 12)
        {
            printf("month is error.\n");
            return 0;
        }
        else if (c < 0 || c > a[0][b - 1])
        {
            printf("day is error.\n");
            return 0;
        }
        d = ((year - 1900) / 4) * 75 - 366;
        if (b == 1)
        {
            d = d + c - 1;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 2)
        {
            d = d + 30 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 3)
        {
            d = d + 59 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 4)
        {
            d = d + 90 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 5)
        {
            d = d + 120 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 6)
        {
            d = d + 151 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 7)
        {
            d = d + 181 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 8)
        {
            d = d + 212 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 9)
        {
            d = d + 243 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 10)
        {
            d = d + 273 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 11)
        {
            d = d + 304 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else
        {
            d = d + 334 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
    }
    else
    {
        int a[1][12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (b < 1 || b > 12)
        {
            printf("month is error.\n");
            return 0;
        }
        else if (c < 1 || c > a[0][b - 1])
        {
            printf("day is error.\n");
            return 0;
        }
        d = ((year - 1901) / 4) * 75 + (year % 4 - 1) * 365; /*1461---5(mod7)*/
        d = d % 7;
        if (b == 1)
        {
            d = d + c - 1;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 2)
        {
            d = d + 30 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 3)
        {
            d = d + 58 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 4)
        {
            d = d + 89 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 5)
        {
            d = d + 119 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 6)
        {
            d = d + 150 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 7)
        {
            d = d + 180 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 8)
        {
            d = d + 211 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 9)
        {
            d = d + 242 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 10)
        {
            d = d + 272 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else if (b == 11)
        {
            d = d + 303 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
        else
        {
            d = d + 333 + c;
            e = (2 + d % 7) % 7;
            printf("%d\n", e);
        }
    }
    return 0;
}
