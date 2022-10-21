#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    scanf("%s",s);
    int L=strlen(s),ispalind();
    for(int l=L;l>=2;l--)
    {
        for(int i=0;i<=L-l;i++)
        {
            if(ispalind(s,i,i+l-1))
            {
                for(int j=i;j<=i+l-1;j++)
                printf("%c",s[j]);
                printf("\n");
                return 0;
            }
        }
    }
    printf("No Output\n");
    return 0;

}
int ispalind(char s[],int left, int right) //left:开始下标，right：结束下标  
{
    if(s[left]==s[right]&&left<right)
    {
        left++;
        right--;
        return ispalind(s,left,right);
    }
    else if(left==right||left==right+1) return 1;
    else return 0;
}