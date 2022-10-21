#include <stdio.h> 
#include <string.h> 
#define ICLLEN 100
#define STRLEN 1000
int countsub( char *str, char *ss )
{
    int count=0,lss=strlen(ss);
    int lstr=strlen(str);
    int max=0;//max记录最长的连续数列geshu
    for(int i=0;i<=lstr-lss;i++)
    {
        int j=0;
        while(j<lss&&*(ss+j)==*(str+i+j))/*j对应不相等的数*/
        {
            j++;
        }
        if(j==lss)/*字符串相等*/
        {
            i+=lss-1;
            count++;
            if(count>max) max=count;
        }
        else
        {
            count=0;
        }
    }
    return max;
} 
int countsub(char *,char *);

int main( )  
{  
    char s1[STRLEN] = {0}, s2[ICLLEN] = {0};  
    gets(s1);  
    gets(s2);  
    printf("%d\n", countsub( s1, s2 ) );  
    return 0;
}