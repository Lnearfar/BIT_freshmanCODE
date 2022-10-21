/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char *resort(char *a)
{
    char *p = a, *l = a;
    while (*l != '\0')
    {
        l++;
    } //l指向最后的‘0’
    int L = l - p;
    for (int i = L - 1; i >= 1; i--) //i指向最后一位
    {
        char *max = a;
        for (int j = 1; j <= i; j++)
        {
            if (*(a + j) > *max)
            {
                max = a + j;
            }
        }
        if (max != a + i)
            swap(max, a + i);
    }
    return a;
}

char *resort(char *a);
int main(int argc, char *argv[])
{

    char a[100];
    gets(a);
    puts(resort(a));
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */