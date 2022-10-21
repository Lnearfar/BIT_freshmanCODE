#include<stdio.h>
#include<string.h>
int W[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char Y[12]={'1','0','X','9','8','7','6','5','4','3','2','\0'};
int main()
{
    int N,i,j;
    void move(),pt();
    char calculate();
    char number[19];
    printf("Enter how many IDnumber should you enquire:");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s",number);
        int l=strlen(number);
        if(l!=15&&l!=18)
        {
            printf("Invalid\n");
            continue;
        }
        if(l==15)/*15位身份证*/
        {
            if(number[12]=='9'&&number[13]=='9'&&((number[14]=='6')||(number[14]=='7')||(number[14]=='8')||(number[14]=='9')))
            {
                move(18,number);
                number[17]=calculate(number);
                pt(number);
            }
            else
            {
                move(19,number);
                number[17]=calculate(number);
                pt(number);
            }
        }
        else/*18位身份证*/
        {
            if(number[17]==calculate(number)) printf("Valid\n");
            else printf("Invalid\n");
        }
    }
    return 0;
}
void move(int n,char *p)
{
    char *pend=p+16;
    for(;pend>=p+8;pend--)
    {
        *(pend)=*(pend-2);
    }
    if(n==18)
    {
        *(p+6)='1';*(p+7)='8';
    }
    else 
    {
        *(p+6)='1';*(p+7)='9';
    }
}    
char calculate(char *pnumber)
{
    int s=0,i;
    for(i=0;i<=16;i++)
    {
        s+=W[i]*(*(pnumber+i)-48);
    }
    s%=11;
    char c=Y[s];
    return c;
}
void pt(char *pnumber)
{
    for(int i=0;i<=17;i++)
    {
        printf("%c",*(pnumber+i));
    }
    printf("\n");
}