#include<stdio.h>
int main()
{
    int n,k;
    char C,p;
    scanf("%d %c",&n,&C);
    if((C<'A')||(C>'z')||((C>'Z')&&(C<'a')))
    {
        printf("Data Error!\n");
    }
    else
    {
        if(C>=97)
        {
            k=C-'a'+n;
            while(k<0)
            {
                k+=26;
            }
            k=k%26;
            p=k+'a';
            printf("%c\n",p);
        }
        else
        {
            k=C-'A'+n;
            while(k<0)
            {
                k+=26;
            }
            k=k%26;
            p=k+'A';
            printf("%c\n",p);
        }
    }
    return 0;
}