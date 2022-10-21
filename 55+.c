#include<stdio.h>
#include<string.h>
#define STRLEN 10000
char code[STRLEN]={0};

void pt(char,int);

int main()
{
    int i=0,infor=0,space=0;//infor表示；在不在for循环里
    while(1)
    {
        code[i]=getchar();
        if(code[i]=='\n') continue;
        else if(code[i]!=EOF) i++;
        else break;
    }
    for(i=0;code[i]!=EOF;i++)
    {
        if(i>0&&code[i]=='>'&&code[i-1]=='h') printf(">\n");
        else if(code[i]=='{')
        {
            printf("%c\n",code[i]);
            pt(' ',4*++space);
        }
        else if(code[i]=='}')
        {
            printf("}\n");
            if(code[i+1]=='}') pt(' ',4*(--space-1));
            else pt(' ',4*--space);
        }
        else if(code[i]==';')
        {
            if(infor)
            { pt(';',1);infor--;
            }
            else if(code[i+1]=='}')
            {
                printf(";\n");
                pt(' ',4*(space-1));
            }
            else 
            {
                printf(";\n");
                pt(' ',4*space);
            }
        }
        else 
        {
            if(code[i]=='f'&&code[i+1]=='o'&&code[i+2]=='r') infor=2;
            if(code[i+1]=='{'||code[i+1]=='}')
            {
                printf("%c\n",code[i]);
                pt(' ',4*space);
            }
            else 
            {
                printf("%c",code[i]);
            }
        }
    }
    return 0;
}

void pt(char c,int k)
{
    for(int i=1;i<=k;i++)
    {
        printf("%c",c);
    }
}