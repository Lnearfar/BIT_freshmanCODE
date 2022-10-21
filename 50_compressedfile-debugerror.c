#include<stdio.h>
#include<string.h>
#define LINE 10000
#define WORDSLENGTHS 16
static char word[LINE][WORDSLENGTHS];
int compare( char *ptemp, char (*pword)[WORDSLENGTHS],int L)//ptmep指向temp，pword指向word，L表示word中已经存的数的个数
{
    for(int i=0;i<=L-1;i++)
    {
        if(strcmp(ptemp,*(pword+i))==0)
        {
            return i;
        }
    }
    return L;
}
int main()
{
    char s[82],tempword[WORDSLENGTHS];
    int wordsnum=0,lines=0,j=0,compare();

    //for(int lines=0;;lines++)//一行一行开始输入
    while(fgets(s,82,stdin))
    {
        char *p=s;
        int l=0;
        j=0;
        while(*(p+j)!='\n')//用p+j遍历s字符串数组
        {
            if(*(p+j)>='A'&&*(p+j)<='Z'||*(p+j)>='a'&&*(p+j)<='z')//p+j是字母
            {
                tempword[l]=*(p+j);
                l++;
            }
            else//p+j不是字母
            {
                if(j==0) //s[0]是个非字母
                {
                    printf("%c",s[0]);
                }
                else
                {
                    if(*(p+j-1)>='A'&&*(p+j-1)<='Z'||*(p+j-1)>='a'&&*(p+j-1)<='z')//如果输入的空格或逗号前是字母
                    {                                                             //表示要结束这个单词
                        tempword[l] = '\0';
                        if (compare(tempword, word, wordsnum) == wordsnum) //tempword没有出现过
                        {
                            strcpy(word[wordsnum], tempword);
                            wordsnum++;
                            printf("%s",tempword);
                            printf("%c",*(p+j));
                            l=0;
                        }
                        else//tempword出现过
                        {
                            printf("%d",compare(tempword, word, wordsnum)+1);
                            printf("%c",*(p+j));
                            l=0;
                        }
                    }
                    else//前面就是一个符号，直接原样输出即可
                    {
                        printf("%c",*(p+j));
                    }
                }
            }
            j++;
        }
        if(j==0)
        {
            printf("\n");continue;
        }
        else if(*(p+j-1)>='A'&&*(p+j-1)<='Z'||*(p+j-1)>='a'&&*(p+j-1)<='z')//如果最后一位是字符
        //，则上方未能输出,且未存放到word中
        {
            if (compare(tempword, word, wordsnum) == wordsnum) //tempword没有出现过
            {
                strcpy(word[wordsnum], tempword);
                wordsnum++;
                printf("%s", tempword);
                l = 0;
            }
            else //tempword出现过
            {
                printf("%d", compare(tempword, word, wordsnum) + 1);
            }
        }
        printf("\n");
    }
    return 0;
}