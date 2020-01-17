#include<stdio.h>
#include<math.h>

bool isprime(int n)
{
	if(n==2 || n==3 || n==5 || n==7)
		return true;
	else if(n%2==0 || n%3==0 || n%5==0 || n%7==0)
		return false;
	for(int i=7;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}

int nextprime(int n, int i)
{
	while(1)
	{
		i++;
		if(n%i==0 && isprime(i))
			return i;
	}
	
}

int main()
{
	printf("Enter The Number: ");
	int n;
	scanf("%d",&n);
	
	int count=0,i=2;
	while(n!=1)
	{
		if(n%i==0)
		{
			count++;
			n=n/i;
			if(n%i!=0)
			{
				if(n!=1)
				{
					printf("%d^%d * ",i,count);
					count = 0;
				}
				else
				{
					printf("%d^%d",i,count);
					count = 0;
				}
				
			}
		}
		else
		{
			i = nextprime(n,i);
		}
	}
}
