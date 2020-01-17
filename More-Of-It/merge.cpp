#include<stdio.h>


void merge_array(int *arr, int left, int mid, int right){
	
	int n1 = mid-left+1;
	int n2 = right-mid;
	
	int left_arr[n1], right_arr[n2];
	
	for(int i=0;i<n1;i++)
		left_arr[i] = arr[left+i];
	for(int i =0;i<n2;i++)
		right_arr[i] = arr[mid + 1 + i];
	
	int i =0, j=0, index = left;
	while(i<n1 && j<n2){
		if(left_arr[i]<=right_arr[j]){
			arr[index] = left_arr[i];
			i += 1;
		}
		else{
			arr[index] = right_arr[j];
			j += 1;
		}
		index += 1;
	}
	
	while(i<n1){
		arr[index] = left_arr[i];
		index += 1;
		i += 1;
	}
	
	while(j<n2){
		arr[index] = right_arr[j];
		index += 1;
		j += 1;
	}
}


void merge_sort(int *arr, int left, int right){
	if(left<right){
		int mid = left + (right - left)/2;
		
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		
		merge_array(arr, left, mid, right);
	}
}


int main(){
	printf("Enter the number of elements: ");
	int n;
	scanf("%d",&n);
	int arr[n];
	
	printf("Please Enter %d Elements: ",n);
	
	for(int i =0;i<n;i++)
		scanf("%d",&arr[i]);
		
	printf("Array after using Merge Sort Algorithm");
	
	merge_sort(arr, 0, n-1);
	
	for(int i =0;i<n;i++)
		printf("%d ",arr[i]);
}
