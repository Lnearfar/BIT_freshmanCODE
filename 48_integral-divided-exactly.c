#include<stdio.h>
int main()
{
	int n,a[5],N[3],k,i,temp;
	scanf("%d",&k);
	for(n=10000;n<=30000;n++)
	{
		temp=n;
	    for(i=0;i<=4;i++)
	    {
	       a[i]=temp%10;
	       temp/=10;
	    }
	    for(i=2;i>=0;i--)
	    {
	    	N[i]=100*a[i+2]+10*a[i+1]+a[i];
		}
		if(N[0]%k==0&&N[1]%k==0&&N[2]%k==0)
		printf("%d\n",n);
	}
	return 0;
}