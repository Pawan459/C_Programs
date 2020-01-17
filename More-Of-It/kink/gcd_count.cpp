#include<stdio.h>
#include<math.h>

unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
	if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}

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

unsigned long long int count(unsigned long long int n)
{
	unsigned long long int i=2,count=0,ans=1;
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
					//printf("%d^%d * ",i,count);
					ans = ans*(count+1);
					count = 0;
				}
				else
				{
					//printf("%d^%d",i,count);
					ans = ans*(count+1);
					count = 0;
				}
				
			}
		}
		else
		{
			i = nextprime(n,i);
		}
	}
	
	return ans;
}

main()
{
	unsigned long long int a,b,c;
	scanf("%llu%llu",&a,&b);
	c=gcd(a,b);
	printf("%llu",count(c));
}
