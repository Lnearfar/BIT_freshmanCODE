#include <stdio.h>
int main()
{
	char a,s[10000]={0};
	int i=0,j,k=0,n;
	
	while(1)
	{
		a=getchar();
		
		if(a==EOF)
			break;
		
		if(a!='\n')
		{
			s[i]=a;
			i++;
		}
	}

	printf("%c",s[0]);
	
	for(i=1;s[i]!='\0';i++)
	{
		printf("%c",s[i]);
		 
		
		if(s[i]=='>'&&s[i-1]=='h')
			printf("\n");
		
		else if(s[i]==')')
		{
			if(s[i-1]=='(')
			{
				if(s[i+1]=='{')//(){
				{
					printf("\n");
					k=0;
				}
			}
			
			else
			{
				if(s[i+1]=='{')//){
				{	
					printf("\n");
					
					for(j=1;j<=k;j++)
						printf("    ");
				}
			}
				
		}
		
		else if(s[i]=='{')
		{
			k++;
			printf("\n");
			for(j=1;j<=k;j++)
				printf("    ");
		}
		
		else if(s[i]==';')
		{
			if(s[i-3]!=s[i+1]&&s[i+2]!='+'&&s[i+2]!='-')
			{
				printf("\n");
				
				if(s[i+1]=='}')
					k--;	
				
				for(j=1;j<=k;j++)
					printf("    ");	
			}
			
		}

		
		else if(s[i]=='}')
		{
			if(s[i+1]=='}')
				k--;

			printf("\n");
			
			for(j=1;j<=k;j++)
				printf("    ");
		}
	}
}
