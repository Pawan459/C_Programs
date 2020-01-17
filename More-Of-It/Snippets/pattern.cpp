#include<stdio.h>
int main()
{
	int i,k,l;
	k=0;l=4;
	for(i=0;i<5;i++)
	{
		/* 
		
		 *123*
		 0*2*4
		 01*34
		*/
		if(i==k && k!=l)
			printf("*");
		else
			printf(" ");
		if(i==l && k!=l)
		{
			k++;
			i=-1;
			l--;
			printf("*");
			printf("\n");
		}
		if(i==k && k==l)
		{
			printf("*");
			break;
		}
		
	}
}
