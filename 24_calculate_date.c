#include<stdio.h>
int main()
{
    int year,month,day,period,i;
    scanf("%d %d %d %d",&year,&month,&day,&period);
    int a[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    for(i=1;i<=period;i++)
    {
        if(year%4==0&&year%100!=0||year%400==0)/*leap year*/
        {
            if(month==12)
            {
                if(day==31)
                {
                    day=1;month=1;year+=1;
                }
                else
                {
                    day+=1;
                }
            }
            else
            {
                if(day==a[1][month-1])
                {
                    month+=1;
                    day=1;
                }
                else
                {
                    day+=1;
                }
            }
        }
        else
        {
            if(month==12)
            {
                if(day==31)
                {
                    day=1;month=1;year+=1;
                }
                else
                {
                    day+=1;
                }
            }
            else
            {
                if(day==a[0][month-1])
                {
                    month+=1;
                    day=1;
                }
                else
                {
                    day+=1;
                }
            } 
        }
    }
    printf("%d.%d.%d\n",year,month,day);
    return 0;
}