#include <stdio.h>
#include <string.h>

char outputs[7], str[7];

void AddZero(char *s, int k) //add (5-k)0 to s
{
    char *p = s + 4;
    for (int i = 0; i < k; i++)
    {
        *p = *(p + k - 5);
        p--;
    }
    for (int i = 0; i < 5 - k; i++)
    {
        s[i] = '0';
    }
    s[5] = '\0';
}

void DecToHex(char c)
{
    if (c == '0')
    {
        strcpy(outputs, "7D");
    }
    else if (c == '1')
    {
        strcpy(outputs, "50");
    }
    else if (c == '2')
    {
        strcpy(outputs, "37");
    }
    else if (c == '3')
    {
        strcpy(outputs, "57");
    }
    else if (c == '4')
    {
        strcpy(outputs, "5A");
    }
    else if (c == '5')
    {
        strcpy(outputs, "4F");
    }
    else if (c == '6')
    {
        strcpy(outputs, "6F");
    }
    else if (c == '7')
    {
        strcpy(outputs, "54");
    }
    else if (c == '8')
    {
        strcpy(outputs, "7F");
    }
    else
    {
        strcpy(outputs, "5F"); //????what is number 9's consequence?
    }
}

int main()
{
    while (1)
    {

        scanf("%s", str);
        getchar();
        if (strcmp(str, "0") == 0)
        {
            return 0;
        }
        int k = strlen(str);
        if (k < 5)
        {
            AddZero(str, k);
        }
        for (int i = 0; i < 5; i++)
        {
            DecToHex(str[i]);
            printf("%s", outputs); // Decimal to Hexadecimal
            if (i == 4)
            {
                printf("\n");
            }
            else
                printf(" ");
        }
    }
    return 0;
}