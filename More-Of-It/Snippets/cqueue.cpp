#include<stdio.h>
#include<stdlib.h>
struct queue{
	int data;
	struct queue *next;
};

struct queue *front;

struct queue* insert()
{
	struct queue *rear;
	rear=(struct queue*)malloc(sizeof(struct queue));
	printf("Enter the Number");
	int num;
	scanf("%d",&num);
	rear->data=num;
	rear->next=front; //pointing it to our first node
	front=rear;		//saving the address of newnode in our first node
	return front;
}

void display(struct queue *front)
{
	while(front!=NULL)
	{
		printf("%d ->",front->data);
		front=front->next;
	}
}

int main()
{
	struct queue *front;
	while(1)
	{
		
		printf("\n1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					front=insert();
					break;
				}
			case 2:
				{
					struct queue *ptr=front;
					front=front->next;
					free(ptr);
					break;
				}
			case 3:
				{
					display(front);
					break;
				}
		}
	}
	
}
