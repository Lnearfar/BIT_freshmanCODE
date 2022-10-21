#include<stdio.h>
#include<string.h>
#define STRLEN 1000
#define LINE 1000

void pt(char,int );

int main()
{
    int ln=0,space=0,infor=0;//space表示缩进
    char map[LINE][STRLEN];
    while(fgets(map[ln],STRLEN,stdin))
    {
        int i,lln=strlen(map[ln]);
        for(i=0;i<lln;i++)
        {
            if(map[ln][i]=='\0') break;
            else if(map[ln][i]=='\n') continue;
            else if(i>=1&&map[ln][i]=='>'&&map[ln][i-1]=='h') 
            {
                printf(">\n");
            }
            else if(map[ln][i]==';')//;
            {
                if(infor)
                {
                    pt(';',1);
                    infor--;
                }
                else//; is not in for
                {
                    if(map[ln][i+1]=='}'||map[ln][i+1]=='{')
                    {
                        pt(';',1);
                    }
                    else//；后面不是}
                    {
                        pt(';',1);
                        pt('\n',1);
                        pt(' ',4*space);
                    }
                }
            }
            else if(map[ln][i]=='{')//{}
            {
                if(!(i==0&&map[ln - 1][strlen(map[ln - 1])-2]=='{'||map[ln][i-1]=='{')) pt('\n',1);
                pt(' ',4*space);
                space++;
                pt('{',1);
                pt('\n',1);
            }
            else if(map[ln][i]=='}')//}
            {
                if(!(i==0&&map[ln - 1][strlen(map[ln - 1])-2]=='}'||map[ln][i-1]=='}')) pt('\n',1);
                space--;
                pt(' ',4*space);
                pt('}',1);
                pt('\n',1);
            }
            else //字符或空格
            {
                if (map[ln][i] == 'f' && map[ln][i+1] == 'o' && map[ln][i+2] == 'r')
                {
                    infor = 2;
                }
                if (i == 0)
                {
                    if ((map[ln - 1][strlen(map[ln - 1])-2] == '{' ||map[ln - 1][strlen(map[ln - 1])-2] == '}')&& ln > 0) //{int am}
                    {
                        pt(' ', 4 * space);
                        pt(map[ln][i], 1);
                    }
                    else
                    pt(map[ln][i], 1);
                }
                else if (map[ln][i - 1] == '{' || map[ln][i - 1] == '}') //{i
                {
                    pt(' ', 4 * space);
                    pt(map[ln][i], 1);
                }
                else
                {
                    pt(map[ln][i], 1);
                }
            }  
        }
        ln++;
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