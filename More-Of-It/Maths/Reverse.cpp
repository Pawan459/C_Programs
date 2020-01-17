#include<stdio.h>

int Reverse(int n,int k)
{
	int arr[n],temp[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		int l=n-1,a=i;
		while(l>=i)
		{
			temp[a]=arr[l];
			a++;
			l--;
		}
		for(int j=0;j<n;j++)
		{
			arr[j]=temp[j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(k==arr[i])
		{
			k=i;
			break;
		}
	}
	
	return k;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int result=Reverse(n,k);
		printf("%d\n",result);
	}
}
