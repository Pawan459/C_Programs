#include<stdio.h>

int main()
{
	int a[3],b[3];
	for(int i=0;i<3;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i =0;i<3;i++)
	{
		scanf("%d",&b[i]);
	}
	int a_p=0, b_p=0;
	for(int i=0;i<3;i++)
	{
		if(a[i]>b[i])
			a_p++;
		else if(b[i]>a[i])
			b_p++;
	}
	
	printf("%d %d",a_p,b_p);
	
	return 1;
}
