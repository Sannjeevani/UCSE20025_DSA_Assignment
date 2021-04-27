#include<stdio.h>
#include<stdlib.h>

struct node{
	int datas;
	struct node *left, *right;
};

struct node *insert(struct node *root, int s){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> datas = s;
	temp -> left = temp-> right = NULL;
	
	if(root == NULL){
		root = temp;
	}
	if(s < root-> datas){
		root -> left = insert(root->left, s);
    }
	if(s > root->datas){
		root -> right = insert(root->right, s);
	}
	return (root);
}

void printPreorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	printf("%d ", node->datas); 
	printPreorder(node->left); 
	printPreorder(node->right); 
}

void printpostorder(struct node* node){
	if (node == NULL) 
		return; 

	printpostorder(node->left); 
	printpostorder(node->right);
	printf("%d ", node->datas); 
}

void printinorder(struct node* node){
	if (node == NULL) 
		return; 

	printinorder(node->left);
	printf("%d ", node->datas); 
	printinorder(node->right);
}


void main(){
  int tree[] = {2,13,1,55,76,3,4,3,12,90};
	int i;
	struct node *root = NULL;
	for (i=0; i <= 10; i++){
		root = insert(root, tree[i]);
	}
	
	printf("Preorder traversal : ");
	printPreorder(root);
	printf("\n\nInorder traversal : ");
	printinorder(root);
	printf("\n\nPostorder traversal : ");
	printpostorder(root);
}
