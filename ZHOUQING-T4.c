#include <stdio.h>  
#include <string.h>  
  
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
  
int main()  
{  
    char a[100];  
    int left,right;  
  
    gets(a);  
    left = 0;  
    right = strlen(a)-1;  
    if(ispalind(a,left,right)) printf("Yes\n");  
    else printf("No\n");  
    return 0;
}  