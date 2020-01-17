#include<stdio.h>
#include<stdlib.h>


struct tree{
	int data;
	struct tree *left=NULL;
	struct tree *right=NULL;
};

//function to sort
void sort(int *arr,int n)
{
	for(int i=1;i<n;i++)
	{
		int temp=arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}

int main()
{
	printf("Enter the Number of Data ");
	int n;
	scanf("%d",&n);
	int arr[n];
	
	//Taking Inputs
	for(int i=0;i<n;i++)
	{
		printf("Enter the %d number ",i+1);
		scanf("%d",&arr[i]);
	}
	
	//
	sort(arr,n);
	
	for(int i=0;i<n;i++)
	{
		printf("%d \n",arr[i]);
	}
}
