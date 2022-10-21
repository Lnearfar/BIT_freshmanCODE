#include<stdio.h>
#include<string.h>
#define STRLEN 23
void Preverspt(int,int,char *);
void Ereverspt(int,int,char *);
int main()
{
    int N;
    scanf("%d",&N);
    getchar();
    for(int nn=0;nn<N;nn++)
    {
        char s[STRLEN];
        gets(s);
        int Ls=strlen(s),i;
        for(i=0;i<Ls&&s[i]>=48&&s[i]<=57;i++);
        if(i==Ls)//s为整数
        {
            if(s[0]=='0'&&Ls==1)//s=0
            { 
                printf("0\n");
            }
            else
            {
                int j=Ls-1;
                while(s[j]=='0'&&j>0) j--;
                if (s[j] == 0)
                {
                    printf("0\n");
                }
                else
                {
                for(int k=j;k>=0;k--) printf("%c",s[k]);
                printf("\n");
                }
            }
        }
        else
        {
            if(s[i]=='.')//a.b
            {
                Preverspt(0,i-1,s);
                printf(".");
                Preverspt(i+1,Ls-1,s);
                printf("\n");
            }
            else if(s[i]=='/')//a/b
            {
                Ereverspt(0,i-1,s);
                printf("/");
                Ereverspt(i+1,Ls-1,s);
                printf("\n");
            }
            else//%
            {
                Ereverspt(0,Ls-2,s);
                printf("%c\n",'%');
            }
        }
    }
    return 0;
}
void Preverspt(int left,int right,char *number)//假定左到右都是整数
{
    char *p=number+right;
    int i=0;
    while(*(p-i)=='0'&&i<right) {i++;}
    int j=0;
    while(*(number+left+j)=='0') {j++;}
    if(number+left+j>p-i)//输入只有0
    {
        printf("0");
    }
    else
    {
        while (p - i >= number + left + j)
        {
            printf("%c", *(p - i));
            i++;
        }
    }
}
void Ereverspt(int left,int right ,char *number)//保留左部分0
{
    char *p=number+right;
    int i=0;
    while(*(p-i)=='0'&&i<right) {i++;}
    if(*(p-i)==0) printf("0");
    else
    {
        while (p - i >= number + left)
        {
            printf("%c", *(p - i));
            i++;
        }
    }
}