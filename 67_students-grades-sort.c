#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char Name[10];
    int grade;
} STUDENT;

STUDENT ReportCard[100];

void swap(int m, int n)
{
    int t;
    char ts[10] = {0};
    t = ReportCard[m].grade;
    ReportCard[m].grade = ReportCard[n].grade;
    ReportCard[n].grade = t;
    strcpy(ts, ReportCard[m].Name);
    strcpy(ReportCard[m].Name, ReportCard[n].Name);
    strcpy(ReportCard[n].Name, ts);
}

void sort(int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int min = 0;
        for (int j = 1; j <= i; j++)
        {
            if (ReportCard[j].grade <= ReportCard[min].grade)
                min = j;
        }
        if (i != min)
        {
            swap(i, min);
        }
    }
}

void InputGrades(int i)
{
    char s;
    int j;
    for (j = 0; (s = getchar()) != ','; j++)
    {
        ReportCard[i].Name[j] = s;
    }
    ReportCard[i].Name[j] = '\0';
    scanf("%d", &(ReportCard[i].grade));
    getchar();
}

void OutputGrade(int i)
{
    printf("%s,%d\n", ReportCard[i].Name, ReportCard[i].grade);
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        InputGrades(i);
    }
    sort(n);
    for (int i = 0; i < n; i++)
    {
        OutputGrade(i);
    }
    return 0;
}