#include<stdio.h>
int table_year[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,1},{0,31,29,31,30,31,30,31,31,30,31,30,2}};
int main()
{
    int i,n,day=1,year,count=0,judge(),M[12];
    scanf("%d",&n);
    for(year=1900;year<n;year++)
    {
        if(year%4==0&&year%100!=0||year%400==0) day+=table_year[1][12];
        else day+=table_year[0][12];
    }
    for(int month=1;month<=12;month++)
    {
        if(judge(day,month,n)==1) 
        {
            M[count++]=month;
        }
    }
    if(count==1)
    {
        printf("There is 1 Black Friday in year %d.\n",n);
        printf("It is:\n%d/%d/13\n",n,M[0]);
        return 0;
    }
    else
    {
        printf("There are %d Black Fridays in year %d.\n",count,n);
        printf("They are:\n");
        count--;
        for(i=0;i<=count;i++) printf("%d/%d/13\n",n,M[i]);
        return 0;
    } 
    
}
int judge(int day,int month,int Year)
{
    int sign=(Year%4==0&&Year%100!=0||Year%400==0);
    for(int i=1;i<=month-1;i++)
    {
        day+=table_year[sign][i];
    }
    day=(day+12)%7;
    if(day==5) return 1;
    else return 0;
}
