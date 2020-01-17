#include<stdio.h>
int main()
{
	int i,n,a[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	int j,temp;
	for(i=1;i<n;i++)
  {
    temp=a[i];
    j=i-1;
    while(temp<=a[j] && j>=0)
    {
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=temp;
  }
  int count=0;
  for(i=0;i<n;i++)
  {
  	if(a[i+1]!=a[i])
  		count=count+1;
  }
  printf("%d",count);
}
