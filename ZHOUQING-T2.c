#include<stdio.h>  
int main()  
{  
    int lines=1,words=0,chars=0,i,signal=0;  
    char a[10000];  
    a[0]=a[1]='\n';  
    for(i=2;i<=10000;i++)  
    {  
        a[i]=getchar();  
        if(a[i]==EOF)  
        {  
            lines--;  
            break;  
        }  
        chars++;  
        if(a[i]=='\n')  
        {  
            lines++;  
        }  
        if(((a[i-2]=='\n')||(a[i-2]==' ')||(a[i-2]=='\t'))&&(((a[i-1]>=65)&&(a[i-1])<=90)||((a[i-1])>=97&&(a[i-1]<=122)))&&(((a[i-1]>=65)&&(a[i-1])<=90)||((a[i-1])>=97&&(a[i-1]<=122))))  
        {/*space letter letter*/  
            signal=1;  
        }/*((a[i-2]<=64)||a[i-2]>=123||((a[i-2]>=91)&&(a[i-2]<=96)))refers to a is not a letter*/  
        if((((a[i-2]<=64)||a[i-2]>=123||((a[i-2]>=91)&&(a[i-2]<=96)))&&(a[i-2]!='\n')&&(a[i-2]!='\t')&&(a[i-2]!=' '))||(((a[i-1]<=64)||a[i-1]>=123||((a[i-1]>=91)&&(a[i-1]<=96)))&&(a[i-1]!='\n')&&(a[i-1]!='\t')&&(a[i-1]!=' '))||(((a[i]<=64)||a[i]>=123||((a[i]>=91)&&(a[i]<=96)))&&(a[i]!='\n')&&(a[i]!='\t')&&(a[i]!=' ')))  
        {  
            signal=0;  
        }  
        if(((a[i]=='\n')||(a[i]==' ')||(a[i]=='\t'))&&(((a[i-1]>=65)&&(a[i-1])<=90)||((a[i-1])>=97&&(a[i-1]<=122)))&&(((a[i-1]>=65)&&(a[i-1])<=90)||((a[i-1])>=97&&(a[i-1]<=122)))&&(signal==1))  
        {  
            signal=0;  
            words++;  
        }  
    }  
    printf("Lines:%d\n",lines);  
    printf("Words:%d\n",words);  
    printf("Chars:%d\n",chars);  
    return 0;  
}  