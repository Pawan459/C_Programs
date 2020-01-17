#include<stdio.h>
int main()
{
  int curr,i,prev,max1,max2;
  
    scanf("%d",&curr);
    prev=curr;
    if(curr==-1)
      return 0;
    else
    {
    	while(curr!=-1)
        {
          if(curr>prev)
          {
          	max2=max1;
          	if(max1>curr)
          	{
          		max1=curr;
   			}
   			else
   			{
   				max2=max1; 				
			}
		  }
          else
          {
          	max2=max1;
          	max1=prev;
		  }
            
          prev=curr;
          scanf("%d",&curr);
          
        }
        printf("%d",max1);
  }
}
