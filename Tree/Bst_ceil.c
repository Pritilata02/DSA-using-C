#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct node *new=NULL;
struct node	*createNode(int data);
struct node *insert(struct node *tree,int el);
int ciel(struct node *tree,int key);
int main()
{
	int ch,el,pos;
	printf("Enter 1 to insert a node in the binary search tree \n\n");
	printf("Enter 2 to find the ciel of a element in bst\n\n");
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
				printf("Enter an element :\n");
				scanf("%d",&el);
				int n=ciel(root,el);
				printf("Ceil of the element is:%d\n",n);
				break;
			default:
				printf("Invalid Choice\n");
		}
	}
}
struct node *createNode(int data) 
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}
struct node *insert(struct node* root,int data)
 	{
    if (root==NULL)
	{
        return createNode(data);
    }

    if(data<root->data)
	{
        root->left=insert(root->left,data);
    }
	else if(data>root->data) 
	{
        root->right=insert(root->right,data);
    }
    return root;
}

int ciel(struct node *root,int key)
{
	int c=-1;
	while(root!=NULL)
	{
		if(root->data==key)
		{
			return key;
		}
		if(root->data>key)
		{
			c=root->data;
			root=root->left;
			
		}
		else
		{
			root=root->right;
		}
	}
	return c;
}






