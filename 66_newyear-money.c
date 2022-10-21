#include <stdio.h>
#include <string.h>

typedef struct Children
{
    char Name[15];
    int ReceiveMoney;
    int GiveMoney;
} CHILDREN;

CHILDREN Kids[50] = {{0}, 0, 0};

//find the subscript of name "s"
int NameSubscript(char *s)
{
    int i = 0;
    while (strcmp(Kids[i].Name, s) != 0)
    {
        i++;
    }
    return i;
}

//collect the imformation and exchange money at the same time
void exchangemoney(void)
{
    char s[15];
    gets(s);
    int k = NameSubscript(s), n; //n is the children number that s will give money
    scanf("%d%d", &(Kids[k].GiveMoney), &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        char ReceiveName[15];
        gets(ReceiveName);
        Kids[NameSubscript(ReceiveName)].ReceiveMoney += (Kids[k].GiveMoney) / n;
    }
    if (n != 0)
        (Kids[k].GiveMoney) = ((Kids[k].GiveMoney) / n) * n;
}

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++)
    {
        gets(Kids[i].Name);
    }
    for (int i = 0; i < N; i++)
    {
        exchangemoney();
    }
    for (int i = 0; i < N; i++)
    {
        printf("%s %d\n", Kids[i].Name, Kids[i].ReceiveMoney - Kids[i].GiveMoney);
    }
    return 0;
}