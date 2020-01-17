#include<stdio.h>
#include<math.h>
int f=0;

//counting number of odd digits
int countodd(int num)
{
	int count=0;
	while(num!=0)
	{
		int rem=num%10;
		if(rem%2!=0)
			count++;
		num=num/10;
	}
	
	return count;
}

int plus(int num)
{
	int count=0;
	while(num%2!=0)
	{
		num=num+1;
		count++;
	}
	f++;
	return count;
}

int minus(int num)
{
	int count=0;
	while(num%2!=0)
	{
		num=num-1;
		count++;
	}
	f++;
	return count;
}

int main()
{
	int t;
	scanf("%d",&t);
	int output=0;
	for(int i=0;i<t;i++)
	{
		int num;
		scanf("%d",&num);
		
		int temp=num;
		int codd=countodd(temp);
		int check=0;
		int j=1;
		while(codd!=0)
		{
			check = check + 5*(int)pow(10,f);
			int rem = temp%(int)pow(10,j);
			int tcount=0;
			if(rem%2!=0)
			{
				if(rem>check)
					tcount=plus(rem);
				else
					tcount=minus(rem);
			}
			else
				f++;
			j++;
			output = output+tcount;
			codd--;
		}
		printf("The output is %d \n",output);
	}
}
