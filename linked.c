#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* insert(struct node *head, int val){
	if(head == NULL){
		struct node *newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = val;
		newnode->next = NULL;
		return newnode;
	}
	struct node *ptr = head;
	while(ptr->next!=NULL)
		ptr = ptr->next;
	
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = NULL;
	ptr->next = newnode;
	return head;
}

void swap(int *a, int *b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}


struct node* InterchangeNode(struct node *head){
	struct node *ptr=head, *fastptr = head;
	while(ptr!=NULL && ptr->next!=NULL)
	{
		int a = ptr->data;
		int b = ptr->next->data;
		swap(&a,&b);
		ptr->data = a;
		ptr->next->data = b;
		fastptr = ptr->next->next;
		ptr = fastptr;
	}
	return head;
}


int main(){
	struct node *head=NULL;
	int i;
	srand(time(0));
	int range = rand()%100 + 1;
	for(i = 1;i<=range;i++)
		head = insert(head, rand()%51);
	
	struct node *ptr = head;
	printf("Your Linked List is: \n");
	while(ptr->next!=NULL){
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n",ptr->data);
	
	head=InterchangeNode(head);
	ptr = head;
	printf("Output Linked List is: \n");
	while(ptr->next!=NULL){
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n",ptr->data);
	
	
}
