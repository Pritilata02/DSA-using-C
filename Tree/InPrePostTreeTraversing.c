#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct node *insert(struct node *tree,long el);
void preorder(struct node *tree);
void inorder( struct node *tree);
void postorder(struct node *tree);
int count = 1;
int main()
{
	int ch,el,pos;
	printf("Enter 1 to insert a node in the binary tree \n\n");
	printf("Enter 2 to display preorder the binary tree \n\n");
	printf("Enter 3 to display inorder the binary tree \n\n");
	printf("Enter 4 to display postorder the binary tree\n\n");
	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter an element : To quit enter 0 :\n");
				scanf("%d",&el);
				while(el!=0)
				{
					root=insert(root,el);
					scanf("%d",&el);
				}
				break;
			case 2:
				printf("Preorder traversing TREE\n");
				preorder(root);
				break;
			case 3:
				printf("Inorder traversing TREE\n");
				inorder(root);
				break;
			case 4:
				printf("Postorder traversing TREE\n");
				postorder(root);
				break;
			default:
				printf("Invalid Choice\n");
		}
	}
} 
struct node *insert(struct node *tree,long el)
{
	if(tree==NULL)
	{
		tree=(struct node *)malloc(sizeof(struct node));
		tree->left=tree->right=NULL;
		tree->data=el;
		count++;
	}
	else
	{
		if(count%2==0)
		{
			tree->left=insert(tree->left,el);
		}
		else
		{
			tree->right=insert(tree->right,el);
		}
	}
	return(tree);
}
void preorder(struct node *tree)
{
	if(tree!=NULL)
	{
		
		printf("%d\n",tree->data);
		preorder(tree->left);
		preorder(tree->right);
		
	}
}
void inorder(struct node *tree)
{
	if(tree!=NULL)
	{
		
		inorder(tree->left);
		printf("%d\n",tree->data);
		inorder(tree->right);
	}
}
void postorder(struct node *tree)
{
	if(tree!=NULL)
	{
		
		preorder(tree->left);
		preorder(tree->right);
		printf("%d\n",tree->data);
	}
}
