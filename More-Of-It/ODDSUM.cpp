#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int even=0,odd=0;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x%2==0)
			even++;
		else
			odd++;
	}
	printf("%d",even*odd);
	
}
