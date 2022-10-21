#include<stdio.h>
int main()
{
    int max,min,i=0,c,anwser;
    char str[10][10],ch,*pstr;
    pstr=str[0];
    int calculate();
    do
    {
        ch=getchar();
        if(ch==',')/*是逗号就结束本次数据输入，跳到下一行中，并判断是否要与max与min交换*/
        {
            *pstr='\0';
            if(i==0)/*如果是第一次输入完就先赋值*/
            {
                max=min=calculate(str[i]);
                pstr=str[++i];
            }
            else
            {
                if(str[i][1]=='\0'&&(str[i][0]<48))/*最后2输入的逗号,数组第二个是\0且第一位不是数字*/
                {
                    continue;
                }
                c=calculate(str[i]);/*用c简代calculate*/
                pstr=str[++i];/*进入下一行数组*/
                if(c>max) max=c;
                if(c<min) min=c;
            }
        }
        if(ch!=',')/*不是逗号就输入到数组中*/
        {
            *pstr++=ch;/*把ch放到数组中*/
        }
    }while(ch!='=');
    *pstr='\0';
    switch(str[i][0])
    {
        case 43:anwser=max+min;break;
        case 45:anwser=max-min;break;
        case 42:anwser=max*min;break;
        case 47:anwser=max/min;break;
        case 37:anwser=max%min;break;
    }
    if(max<0) printf("(%d) %c (%d) = %d\n",max,str[i][0],min,anwser);
    else if(min<0) printf("%d %c (%d) = %d\n",max,str[i][0],min,anwser);
    else printf("%d %c %d = %d\n",max,str[i][0],min,anwser);
    return 0;
}
int calculate(char *pit)
{
    char c;int s=0,symbol=0;
    c=*pit;
    if(c=='-') {pit+=1;symbol=1;}
    while(*pit!='\0')
    {
        c=*pit;
        s=10*s+(c-48);
        pit++;
    }
    if(symbol==1) s=-s;
    return s;
}