#include<stdio.h>
#include<string.h>

#define STRLEN 100000

char str[STRLEN]={0};

int main()
{
    gets(str);
    int L=strlen(str);
    int MaxCount=0,Inseries=0,MaxSubscribe,Subscribe;
    for(int i=1;i<=L;i++)
    {
        if(str[i]==str[i-1]+1)
        {
            if(Inseries==0)
            {
                Subscribe=i-1;
                Inseries=2;
            }
            else
            {
                Inseries++;
            }
        }
        else 
        {
            if(Inseries>MaxCount)
            {
                MaxCount=Inseries;
                MaxSubscribe=Subscribe;
            }
            Inseries=0;
        }
    }
    int i;
    for(i=0;i<MaxCount;i++)
    {
        printf("%c",str[MaxSubscribe+i]);
    }
    printf("\n");
    return 0;
}