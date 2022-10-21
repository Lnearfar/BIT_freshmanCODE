/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int merge_sort(char *a, char *b, char *c)
{
    int i = 0, j = 0;
    while (*(a + i) != '\0' && *(b + j) != '\0')
    {
        if (*(a + i) >= *(b + j))
        {
            *(c + i + j) = *(b + j);
            j++;
        }
        else
        {
            *(c + i + j) = *(a + i);
            i++;
        }
    }
    if (*(a + i) == '\0') //把b填充到c中
    {
        while (*(b + j) != '\0')
        {
            *(c + i + j) = *(b + j);
            j++;
        }
        *(c + i + j) = '\0';
    }
    else
    {
        while (*(a + i) != '\0')
        {
            *(c + i + j) = *(a + i);
            i++;
        }
        *(c + i + j) = '\0';
    }
}

int main(int argc, char *argv[])
{
    char a[100];
    char b[100];
    char c[200];

    gets(a);
    gets(b);
    merge_sort(a, b, c);
    puts(c);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
