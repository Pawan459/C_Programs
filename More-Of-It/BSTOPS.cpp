#include<stdio.h>
#include<stdlib.h>

struct tree{
	long long data;
	long long p;
	struct tree *left;
	struct tree *right;
};

//Global Variables
struct tree *head = NULL;

struct tree * left_most_node(struct tree* root) 
{ 
    struct tree* current = root; 
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 

struct tree* insert_node(struct tree *root, long long key, long long height)
{
	if(root == NULL)
	{
		printf("%lld\n",height);
		struct tree *newnode = (struct tree*)malloc(sizeof(struct tree));
		newnode->data = key;
		newnode->p = height;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	if(root->data>=key)
		root->left =  insert_node(root->left, key, 2*height);
	else
		root->right = insert_node(root->right, key, 2*height + 1);
	return root;
}

struct tree* delete_node(struct tree* root, long long key) 
{ 
    if (root == NULL) return root; 
	  
    if (key < root->data) 
		root->left = delete_node(root->left, key);  
    else if (key > root->data) 
    	root->right = delete_node(root->right, key);
    else
    {
		printf("%lld\n",root->p); 
        if (root->left == NULL) 
        { 
            struct tree *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct tree *temp = root->left;
            free(root); 
            return temp; 
        } 
        struct tree* temp = left_most_node(root->right); 
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data); 
    } 
    return root; 
} 



int main()
{
	long long q;
	scanf("%lld",&q);
	while(q>0)
	{
		char op;
		long long data;
		scanf(" %c %lld",&op,&data);
		if (op == 'i')
			head = insert_node(head, data, 1);	
		else
			head = delete_node(head, data);
		q--;
	}
	return 0;
}
