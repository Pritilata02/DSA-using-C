#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;	
	int priority;
	struct node *link;
};
void insert(int,int);
void display();
struct node *start = NULL;
int main()	
{
	int n,data,p;
	printf("Enter 1 to insert element and it's priority \n");
	printf("Enter 2 to display the queue \n");
	
	while(1)
	{
		printf("\nEnter a Choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the element : ");
				scanf("%d",&data);
				printf("Enter its priority : ");
				scanf("%d",&p);
				insert(data,p);		
				break;
			case 2:
				display();
				break;
			default :
				printf("Invalid choice");
			
		}
	}
}

void insert(int data,int p)
{
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		new->priority=p;
		new->data=data;
		new->link=NULL;
		start=new;
	}
	else if(start->link==NULL)
	{
		if(p>start->priority)
		{
			new->priority=p;
			new->data=data;
			new->link=start;
			start=new;
			
		}
//		else
//		{
//			start->link=new;
//			new->link=NULL;
//		}
	}
	else
		{
			start->link=new;
			new->link=NULL;
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














