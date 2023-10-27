#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
	 
};
void insert_at_begin(int);
void delete_at_begin();
void display();
struct node *start =NULL;
int main()
{
	int ch,el,pos;
		printf("Enter 1 to push an element\n");
		printf("Enter 2 to pop an element\n");
		printf("Enter 3 to display the stack\n");
		printf("Enter 4 to exit\n");
		while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter an Element :");
				scanf("%d",&el);
				insert_at_begin(el);		
				break;
			case 2:
				delete_at_begin();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid Choice\n");
		}
	}
} 
void insert_at_begin(int el)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=el;
	temp->link=start;
	start=temp;
}  
void delete_at_begin()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
	temp=start;
	start=start->link;
	free(temp);
	}
}
void display()
{
	struct node * i;
	i=start;
	while(i!=NULL)
	{
		printf("%d ->",i->data);
		i=i->link;
	}
	printf("NULL\n");
}


