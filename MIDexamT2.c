#include<stdio.h>
#include<string.h>
#define STRLEN 5002
#define RSTLEN 10004
void reverse(char *);
void *multple(char *,char ,char *,int,int );
void plus(char* ,char *,int );
char a[STRLEN],b[STRLEN];
char result[RSTLEN];
char temp[RSTLEN];
int main()
{
    gets(a);
    gets(b);
    if(strcmp(a,"0")==0||strcmp(b,"0")==0)
    {
        printf("0\n");
        return 0;
    }
    int la=strlen(a),lb=strlen(b);
    reverse(a);
    reverse(b);
    int k=0;    //k为循环时b的位数
    for(int i=0;i<RSTLEN-1;i++) result[i]='0';//reset result
    result[RSTLEN-1]='\0';
    for(k=0;k<lb;k++)
    {
        //char temp[RSTLEN];
        multple(temp,b[k],a,k,la);//做乘法
        plus(result,temp,k);//做加法

    }
    //打印出result
    int t=RSTLEN-2;//t points to the last !0 number of results
    while(result[t]=='0')
    {
        t--;
    }
    for(int i=t;i>=0;i--)
    {
        printf("%c",result[i]);
    }
    printf("\n");
    return 0;
}

/*调转a的各个位数*//*入口为字符串地址*/
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

/*num即为a，b的第k位c参与运算，l为a的长度,结果存在temp中*/
void *multple(char *temp,char c,char *num,int k,int l)//num指a
{
    for(int i=0;i<=RSTLEN-2;i++) temp[i]='0';
    temp[RSTLEN-1]='\0';//reset temp
    for(int i=0;i<l;i++)
    {
        int t=(c-48)*(*(num+i)-48);
        temp[k+i]+=t%10;
        temp[k+i+1]+=t/10;
        if(temp[k+i]>=58)
        {
            temp[k+i]-=10;
            temp[k+i+1]++;
        }
    }
}
/*计算result+temp，从k位开始加*/
void plus(char *rst,char *ptemp,int k)
{
    for(int i=k;i<=RSTLEN-3;i++)//暂不使用(*(rst+i)!=0||*(ptemp+i)!=0)
    {
        *(rst+i)+=*(ptemp+i)-48;
        if(*(rst+i)>=58)
        {
            *(rst+i)-=10;
            (*(rst+i+1))++;
        }
    }
}
