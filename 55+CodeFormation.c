#include<stdio.h>
#include<string.h>
#define LINE 200
#define STRLEN 1000
char paper[LINE][STRLEN];
void pt(char ,int);
int main()
{
    int space=0,l=0,infor=0;
    while(fgets(paper[l],STRLEN,stdin))
    {
        for(int i=0;i<strlen(paper[l]);i++)
        {
            if(paper[l][0]=='\n')
            {
                break;
            }
            if(i==0&&paper[l][i]!='}')
            {
                pt(' ',4*space);
            }
            if(paper[l][i]=='{'&&paper[l][i-1]!='{'&&i!=0)
            {
                pt('\n',1);
                pt(' ',4*space++); 
                pt('{',1);
                pt('\n',1);
                pt(' ',4*space);   
            }
            else if(paper[l][i]=='{'&&paper[l][i-1]=='{'&&i!=0)
            {
                pt('{',1);
                pt('\n',1);
                pt(' ',4*++space);
            }
            else if(paper[l][i]=='{'&&i==0&&paper[l][i+1]=='\n')
            {
                space++;
                pt('{',1);
            }
            else if(paper[l][i]=='{'&&i==0&&paper[l][i+1]!='\n')
            {
                pt('{',1);
                pt('\n',1);
                pt(' ',4*++space);
            }
            else if(paper[l][i]=='}'&&paper[l][i+1]!='\n')
            {
                if(paper[l][i-1]!='}'&&paper[l][i+1]!='}')
                {
                    pt('\n',1);
                    space--;
                    pt(' ',4*space);
                    pt('}',1);
                    pt('\n',1);
                    pt(' ',4*space);
                }
                else if(paper[l][i-1]!='}'&&paper[l][i+1]=='}')
                {
                    pt('\n',1);
                    space--;
                    pt(' ',4*space);
                    pt('}',1);
                    pt('\n',1);
                    pt(' ',4*(space-1));
                }
                else 
                {
                    pt('}',1);
                    pt('\n',1);
                    --space;
                    pt(' ',4*(space-1));
                }
            }
            else if(paper[l][i]=='}'&&paper[l][i+1]=='\n')
            {
                if(i==0)
                {
                    pt(' ',4*(--space));
                    pt('}',1);
                    pt('\n',1);  
                }
                else if(paper[l][i-1]!='}')
                {
                    pt('\n',1);
                    pt(' ',4*(--space));
                    pt('}',1);
                }
                else //}}\n
                {
                    pt('}',1);
                    space--;
                }
            }
            else if(paper[l][i]==';')
            {
                if(infor)
                {
                    pt(';',1);
                    infor--;
                }
                else
                {
                    if(paper[l][i+1]=='\n'||paper[l][i+1]=='{'||paper[l][i+1]=='}')
                    {
                        pt(';',1);
                    }
                    else 
                    {
                        pt(';',1);
                        pt('\n',1);
                        pt(' ',4*space);
                    }
                }
            }
            else if(paper[l][i]=='f'&&paper[l][i+1]=='o'&&paper[l][i+2]=='r')
            {
                pt(paper[l][i],1);
                infor=2;
            }
            else pt(paper[l][i],1);
        }
        l++;
    }
    return 0;
}
void pt(char c,int k)
{
    for(int i=0;i<k;i++)
    printf("%c",c);
}