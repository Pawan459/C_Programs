#include<stdio.h>
int main()
{
	int t,sum=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		char a[1000];
		int l=0;
		while(a[l]!='\n')
		{
			scanf("%c",&a[i]);
			l++;
		}
		int j=0;
		while(a[j]!='\n')
		{
			int k=a[j];
			sum=sum+k;
			j++;
		}
		fflush(stdout);
	}
	printf("%d",sum);
}
