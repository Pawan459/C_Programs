#include<stdio.h>
struct student{
	char name[1000];
	int physics;
	int chemistry;
	int maths;
};
int main()
{
	struct student s[100],temp;
	int i,n,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&s[i].name);
		fflush(stdin);
		scanf("%d",&s[i].physics);
		scanf("%d",&s[i].chemistry);
		scanf("%d",&s[i].maths);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(s[i].physics>s[j].physics)
			{
				temp=s[j];
				s[j]=s[i];
				s[j]=temp;	
			}
			else if(s[i].chemistry>s[j].chemistry && s[i].physics==s[j].physics)
			{
				temp=s[j];
				s[j]=s[i];
				s[j]=temp;
			}
			else if(s[i].maths>s[j].maths && s[i].physics==s[j].physics && s[i].chemistry==s[j].chemistry)
			{
				temp=s[j];
				s[j]=s[i];
				s[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s",s[i].name);
		printf("%d",s[i].physics);
		printf("%d",s[i].chemistry);
		printf("%d",s[i].maths);
		printf("\n\n");	
	}
	
	
}
