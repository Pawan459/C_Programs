#include<stdio.h>
int main()
{
  int i,j,n1,n2,a[30],b[30],flag=0,min=0;
  scanf("%d",&n1);
  for(i=0;i<n1;i++)
    scanf("%d",&a[i]);
  scanf("%d",&n2);
  for(i=0;i<n2;i++)
    scanf("%d",&b[i]);
  
  int temp;
  for(i=1;i<n1;i++)
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
  
  for(i=0;i<n1;i++)
  {
    for(j=0;j<n2;j++)
	{
	    if(a[i]!=b[j])
		{
		    if(a[i]<b[j])
			{ 
			    if(a[i]>=min)
				{
			        flag=1;
			        min=a[i];
				}
			}
		}
	    else
		{
	    	flag=0;
	        min=0;
	        break;
	    }      
	}
    if(min==a[i]&&flag==1)
        break;
  }
  if(flag==0)
    printf("NO");
  else
    printf("%d",min);
}
