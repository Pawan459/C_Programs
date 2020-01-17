#include<stdio.h>
int check(int n)
{
	if(n>=3)
		return n/3;
	else
		return 0;
}
int main()
{
	unsigned long int mod0=0,mod1=0,mod2=0;
	unsigned long int N;
	scanf("%lu",&N);
	for(long int i=0;i<N;i++)
	{
		int x;
		scanf("%d",&x);
		if(x%3==0)
			mod0++;
		else if(x%3==1)
			mod1++;
		else
			mod2++;
	}
	//printf("%d %d %d\n",mod0,mod1,mod2);
	printf("%d",(mod0*(mod0-1)*(mod0-2))/6+mod1*mod2*mod0+check(mod1)+check(mod2));
}
