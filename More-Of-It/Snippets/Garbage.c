#include<stdio.h>
int main()
{
  int curr,prev,max1,max2;
  
    scanf("%d",&curr);
    prev=curr;
    max1=prev;
    max2=max1;
    	while(curr!=-1)
        {
          if(curr>prev)
          {
          	if(curr>max1)
          	{
          		max2=max1;
          		max1=curr;
   			}
   			else if(curr>max2)
   			{
   				max2=curr;
			}
		  }
		  else
		  {
			if(curr>max2)
			{
				max2=curr;
			}
			else if(max2==max1)
			{
				max2=curr;
			}
		  }
		 
          prev=curr;
          scanf("%d",&curr);
        }
        printf("%d",max2);
}

