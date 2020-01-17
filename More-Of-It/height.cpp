#include <iostream> 
#include<unordered_set> 
using namespace std; 
struct Node 
{ 
	int key; 
	struct Node* left, *right; 
}; 

Node* makeNode(int data){ 
	Node* newNode = new Node(); 
	newNode->key = data; 
	newNode->right = newNode->right = NULL; 
	return newNode; 
} 

Node* buildTree(int inorder[], int levelOrder[], 
				int iStart, int iEnd, int n) 
{ 
	if (n <= 0) 
		return NULL; 
 
	Node* root = makeNode(levelOrder[0]); 

	int index = -1; 
	for (int i=iStart; i<=iEnd; i++){ 
		if (levelOrder[0] == inorder[i]){ 
			index = i; 
			break; 
		} 
	} 
	unordered_set<int> s; 
	for (int i=iStart;i<index;i++) 
		s.insert(inorder[i]); 
	 
	int lLevel[s.size()]; 
	int rLevel[iEnd-iStart-s.size()]; 
	int li = 0, ri = 0; 
	for (int i=1;i<n;i++) { 
		if (s.find(levelOrder[i]) != s.end()) 
			lLevel[li++] = levelOrder[i]; 
		else
			rLevel[ri++] = levelOrder[i];		 
	}  
	root->left = buildTree(inorder, lLevel, 
				iStart, index-1, index-iStart); 
	root->right = buildTree(inorder, rLevel, 
				index+1, iEnd, iEnd-index); 
	return root; 
} 
 
int maxDepth(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
} 

 
int main() 
{ 
	int in[] = {4, 8, 10, 12, 14, 20, 22}; 
	int level[] = {20, 8, 22, 4, 12, 10, 14}; 
	int n = sizeof(in)/sizeof(in[0]); 
	Node *root = buildTree(in, level, 0, 
						n - 1, n); 

	printf("%d",maxDepth(root))

	return 0; 
} 

