#include<stdio.h>
int AngryRate[8];

int main()
{
    int a,b,max=0;
    AngryRate[0]=0;
    for(int i=1;i<=7;i++)
    {
        scanf("%d%d",&a,&b);
        AngryRate[i]=a+b;
        if(a+b>AngryRate[max]&&(a+b>=10))
        {
            max=i;
        }
    }
    if(max==0)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n",max);
    }
    return 0;
}