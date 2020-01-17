#include<stdio.h>
int fun(int n);
int main()
{
	int N,i,fact;
	scanf("%d",&N);
	/*for(i=1;i<=N;i++)
	{
		fact=fun(i);
		if(fact<=N)
		{
			printf("%d ",fact);
		}
		else
			break;
	}*/
	printf("%d",fun(N)%1000000000);
}
int fun(int n)
{
	int fact=1,k=1;
	while(n+1!=k)
	{
		fact=fact*k;
		printf("%d ",fact);
		k++;
	}
	printf("\n");
	return fact;
}
