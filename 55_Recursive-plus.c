#include<stdio.h>
#include<string.h>
#define IPTLEN 100
#define STRLEN 1000
char result [STRLEN]={'0'};
char a[IPTLEN],b[IPTLEN];
void reverse(char * );
void cstplus(char *,char *);
void plus(char *,char *);

int main()
{
    for(int i=0;i<=STRLEN-2;i++) result[i]='0';
    scanf("%s%s",a,b);
    getchar();
    printf("The sum from %s to %s is ",a,b);
    reverse(a);
    reverse(b);
    cstplus(a,b);
    int i=0;
    while(result[STRLEN-1-i]=='0'){i--;}
    for(int j=i;j>=0;j--)
    {
        printf("%c",result[j]);
    }
    printf("\n");
    return 0;
}

/*cstplus入口为两个整数的字符串，结果存到result数组中*/
void cstplus(char *a,char *b)
{
    plus(result,a);
    plus(a,"1");//记得给a对后加'\0'
    if(strcmp(a,b)==0) 
    {
        plus(result , a);
    }
    else
    {
        cstplus(a,b);
    }
}

/*plus()把b+a的值存入a中*/
void plus(char *a,char *b)
{
    if(*a=='0')
    {
        strcpy(a,b);
        int L=strlen(a);
        a[L]='0';
    }
    else
    {
        int i=0;
        while(*(b+i)!='\0')
        {
            *(a+i)+=*(b+i)-48;
            if(*(a+i)>=58)
            {
                *(a+i)-=10;
                (*(a+i+1))++;
            }
            i++;
        }
        while(*(a+i)==58)
        {
            *(a+i)-=10;
            (*(a+i+1))++;
            i++;
        }
    }
}


void reverse(char *pnum)
{
    int L=strlen(pnum);
    char *l=pnum,*r=pnum+L-1;
    while(r>l)
    {
        char c=*l;
        *l=*r;
        *r=c;
        l++;
        r--;
    }
}
