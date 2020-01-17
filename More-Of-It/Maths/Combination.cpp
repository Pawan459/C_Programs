#include<stdio.h>
#include<conio.h>
unsigned int fact(unsigned int n)
{
	unsigned int res=1;
	while(n!=0)
	{
		res=res*n;
		n--;	
	}	
	return res;
}

unsigned int comb(int n,int r)
{
	return fact(n)/(fact(n-r)*fact(r));
}

int main()
{
	while(1)
	{
		unsigned int n;
		scanf("%d",&n);
		for(unsigned int i=0;i<=n+1;i++)
		{
			unsigned int res=comb(n,i);
			printf("%u ",res);
		}
	}
	return 0;
}
