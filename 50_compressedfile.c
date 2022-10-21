#include<stdio.h>
#include<string.h>
#define WDNUMBER 10000
#define WDLENGTH 20
#define LINELEN 82
char dictionary[WDNUMBER][WDLENGTH];
int number=0;
int main()
{
    int search();
    int judge(char);
    char s[LINELEN],temp[WDLENGTH];
    while(fgets(s,LINELEN,stdin))
    {
        int l = 0;
        for (char *p = s; *p != '\0'; p++)
        {
            if (judge(*p)) //p指向字母
            {
                temp[l] = *p;
                l++;
            }
            else//p指向字符
            {
                if(p==s)//p是第一位
                {
                    printf("%c",*p);
                }
                else//p是后面的
                {
                    if (!judge(*(p-1)))//前面也是字符
                    {
                        printf("%c", *p);
                        continue;
                    }
                    temp[l]='\0';
                    if(*p=='\0') continue;//p指向最后的NULL
                    else//*p结束一个单词
                    {
                        int d=search(dictionary,temp,number);
                        if(d==number)
                        {
                            strcpy(dictionary[number],temp);
                            number++;
                            fputs(temp,stdout);
                            printf("%c",*p);
                            l=0;
                        }
                        else//temp在dictionary中出现过
                        {
                            printf("%d",d+1);
                            printf("%c",*p);
                            l=0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int search(char (*p)[WDLENGTH],char *ptemp,int num)
{
    for(int i=0;i<=num-1;i++)
    {
        if(strcmp(ptemp,*(p+i))==0) return i;
    }
    return num;
}
int judge(char c)
{
    if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') return 1;
    else return 0;
}