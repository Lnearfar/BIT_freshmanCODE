#include <stdio.h>
#include <string.h>
#define IntNum 500

int a[IntNum];

int convert(char *s)
{
    int L = strlen(s), result = 0;
    for (int i = 0; i < L; i++)
    {
        result = result * 10 + s[i] - 48;
    }
    return result;
}

int main()
{
    char s[5];
    int k = 0; //use k to follow the size of the array a[]
    while (scanf("%s", s))
    {
        if (s[0] >= 48) //input char[] is a number
        {
            a[k++] = convert(s);
        }
        else //there have been k numbers in array
        {
            if (s[0] == '+')
            {
                a[k - 2] = a[k - 1] + a[k - 2];
                k--;
            }
            else if (s[0] == '-')
            {
                a[k - 2] = a[k - 2] - a[k - 1];
                k--;
            }
            else if (s[0] == '*')
            {
                a[k - 2] = a[k - 1] * a[k - 2];
                k--;
            }
            else //(s[0] == '/')
            {
                a[k - 2] = a[k - 2] / a[k - 1];
                k--;
            }
        }
        char ch=getchar();
        if(ch=='\n') break;
    }
    printf("%d\n",a[0]);
    return 0;
}
