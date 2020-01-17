#include<stdio.h>
#include<stdlib.h>


struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree* insert(struct tree *root,int data)
{
	if(root==NULL)
	{
		struct tree *node=(struct tree*)malloc(sizeof(struct tree));
		node->data=data;
		node->left=NULL;
		node->right=NULL;
		printf("\nNode Inserted Succesfully\n");
		return node;
	}
	else
	{
		if(data<root->data)
		{
			struct tree *newnode=(struct tree*)malloc(sizeof(struct tree));
			newnode=insert(root->left,data);
			root->left=newnode;
		}
		else
		{
			struct tree *newnode=(struct tree*)malloc(sizeof(struct tree));
			newnode=insert(root->right,data);
			root->right=newnode;
		}
		return root;
	}
}

void display(struct tree *root,int n)
{
	struct tree *ptr=root;
	if(n==1)
	{
		if(ptr==NULL)
			return;
		printf("%d->",root->data);
		display(ptr->left,n);
		display(ptr->right,n);
	}
	else if(n==2)
	{
		if(ptr==NULL)
			return;
		display(ptr->left,n);
		printf("%d->",root->data);
		display(ptr->right,n);
	}
	else if(n==3)
	{
		if(ptr==NULL)
			return;
		display(ptr->left,n);
		display(ptr->right,n);
		printf("%d->",root->data);
	}
	
}

int main()
{
	struct tree *root=NULL;
	printf("Creation Of Binary Search Tree\n");
	while(1)
	{
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Display\n");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("\n Please Enter The Number\n");
				int data;
				scanf("%d",&data);
				root=insert(root,data);
				break;
			}
			case 2:
			{
				printf("\nComing Soon.......\n");
				break;
			}
			case 3:
			{
				int choice;
				printf("\n****************\nChoose How To Display\n****************\n");
				printf("\n1.PreOrder");
				printf("\n2.InOrder");
				printf("\n3.PostOrder\n");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:{
						display(root,choice);
						break;
					}
					case 2:{
						display(root,choice);
						break;
					}
					case 3:{
						display(root,choice);
						break;
					}
					default:{
						printf("\nInvalid Choice\n");
						break;
					}
				}
				break;
			}
			default:{
				printf("Choose Valid Option");
				break;
			}
		}
	}
}
