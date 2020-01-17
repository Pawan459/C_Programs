#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	
	for(register int i=0;i<t;i++)
	{
		int row;
		scanf("%d",&row);
		
		int sum=0;
		for(register int j=0;j<row;j++)
		{
			int max=0;
			for(register int k=0;k<=j;k++)
			{
				int num;
				scanf("%d",&num);
				
				if(max<=num || k==j)
				{
					if(max<=num)
						max=num;
					if(k==j && k!=0)
					{
						sum=sum+max;
					}
				}
			}
		}
		printf("%d\n",sum);
	}
}
