#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* create(struct node *head,int val)
{
	if(head==NULL)
	{
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=val;
		newnode->next=NULL;
		head = newnode;
		return newnode;
	}
	else
	{
		struct node *ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=val;
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=newnode;
	}
	
	return head;
}

void display(struct node *head)
{
	struct node *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->next==NULL)
			printf("%d",ptr->data);
		else
			printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int main()
{
	struct node *head=NULL;
	printf("1.Insert\n2.Display\n");
	while(1)
	{
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
				int val;
				scanf("%d",&val);
				head=create(head,val);
				break;
			}
			case 2:{
				display(head);
				break;
			}
			default:{
				exit(0);
				break;
			}
		}
	}
}
