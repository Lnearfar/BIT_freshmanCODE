#include <stdio.h>
char a[50];
int ChildNum, CountNum, current = 0;

int next(int);

int main()
{

    scanf("%d%d", &ChildNum, &CountNum);
    for (int i = 0; i < ChildNum; i++)
    {
        a[i] = '1';
    }
    for (int i = 1; i <= ChildNum - 1; i++)
    {
        for (int j = 1; j <= CountNum - 1; j++)
        {
            current = next(current);
        }
        a[current] = '\0';
        current = next(current);
    }
    printf("The left child is NO %d.\n", current + 1);
    return 0;
}

int next(int k) //the child[k]'s next child
{
    int m = k + 1;
    while (a[m] == '\0')
    {
        m++;
        if (m >= ChildNum)
        {
            m = 0;
        }
    }
    return m;
}
