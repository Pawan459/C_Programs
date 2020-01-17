#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,count=0;
	scanf("%d %d",&a ,&b);
	for(int i=1;i<=b/2;i++)
	{
		if((int)pow(i,2)<=b && (int)pow(i,2)>=a)
			count++;
		else if((int)pow(i,2)>b)
			break;
	}
	printf("%d %d",count,(int)sqrt(b)-(int)sqrt(a-1));
}
