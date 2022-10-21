#include<stdio.h>
#include<string.h>
#define STRLEN 10
#define RANK 100
int main()
{
    int d[RANK];
    char sentence[RANK][STRLEN];
    for(int k=0;scanf("%d",&d[0])&&d[0]!=0;k++)//输入0停止
    {
        getchar();
        gets(sentence[0]);
        if(strcmp(sentence[0],"right on")==0)//输入第一个就满足
        {
            printf("Tom may be honest\n");
        }
        else
        {
            int line;
            for(line=1;scanf("%d",&d[line]);line++)//输入数
            {
                getchar();
                gets(sentence[line]);
                if(strcmp(sentence[line],"right on")==0) break;
            }
            //line表示最后的下标
            int honest=1;
            for(int i=0;i<line;i++)
            {
                if(strcmp(sentence[i],"too low")==0)
                {
                    if(d[i]>=d[line]) honest=0;
                }
                else
                {
                    if(d[i]<=d[line]) honest=0;
                }
            }
            if(honest==0) printf("Tom is dishonest\n");
            else printf("Tom may be honest\n");
        }
    }
    return 0;
}