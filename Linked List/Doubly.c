#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;	
	struct node *next;
	struct node *prev;
};
void insert_at_begin(int);
void insert_at_end(int);
void insert_at_any_pos(int,int);
void delete_at_begin();
void delete_at_any_pos(int);
void delete_at_end();
void display();
struct node *start = NULL;
struct node *start2 = NULL;
struct node *end;
int main()	
{
	int n,pos,el;
	printf("Enter 1 to insert element at first \n");
	printf("Enter 2 to insert element at any position \n");
	printf("Enter 3 to insert element at last \n");
	printf("Enter 4 to delete the first element\n");
	printf("Enter 5 to delete the last element\n");
	printf("Enter 6 to delete the element at any position\n");
	printf("Enter 7 to display the doubly linked list \n");
	
	while(1)
	{
		printf("\nEnter a Choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the element : ");
				scanf("%d",&el);
				insert_at_begin(el);		
				break;
			case 2:
				printf("Enter the element : ");
				scanf("%d",&el);
				printf("Enter any position : ");
				scanf("%d",&pos);
				insert_at_any_pos(el,pos);
				break;
			case 3:
				printf("Enter the element : ");
				scanf("%d",&el);
				insert_at_end(el);	
				break;
			case 4:
				delete_at_begin();
				break;
			case 5:
				delete_at_end();
				break;
			case 6:
				printf("Enter any Position :");
				scanf("%d",&pos);
				delete_at_any_pos(pos);
				break;
			case 7:
				display();
				break;
			default :
				printf("Invalid choice");
			
		}
	}
}
void insert_at_begin(int el)
{
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	new->data = el;
	new->prev = NULL;
	new->next = start;
	start = new;
	if(new->next != NULL)
	{
		new->next->prev = new;
	}
}
void insert_at_end(int el)
{
	struct node *new,*temp;
	new = (struct node*)malloc(sizeof(struct node));
	temp = start;
	new->data = el;
	new->next = NULL;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	new->prev = temp;
	temp->next = new;
}
void display()
{
	struct node *i;
	i=start;
	
	while( i != NULL)
	{
		printf("%d ->",i->data);
		i=i->next;
	}
	printf("NULL\n");
}

void insert_at_any(int el , int pos)
{
	if(pos<=0)
		printf("Not possible\n");
	else if(pos==1)
		insert_at_begin(el);
	else
	{
		int i = 1;
		struct node *new,*temp,*t;
		temp = start;
		t = start;
		new = (struct node*)malloc(sizeof(struct node));
		new->data = el;
		while(i < pos-1 && temp != NULL)
		{
			temp = temp->next;
			i++;
		}
		if(temp == NULL)
		{
			printf("Invalid position");
		}
		else
		{
			new->prev = temp;
			new->next = temp->next;
			temp->next = new;
			new->next->prev = new;		
		}
	}
}
void delete_at_begin()
{	

	struct node *temp;
	if(start == NULL)
	{
		printf("list is empty");
	}
	else
	{
		temp = start;
		start = start->next;
		start->prev = NULL;
		free(temp);
	}
}
void delete_at_end()
{
	struct node *temp,*i,*t;
	if(start->next==NULL)
	{
			t=start;
			start=NULL;
			free(t);	
	}
	else
	{
		i = start;
		while(i->next->next != NULL)
		{
			i=i->next;
		}
		temp = i->next;
		i->next=NULL;
		free(temp);
	}
}
void delete_at_any_pos(int pos)
{
	if(pos==0)
		printf("Invalid position");
	else if(pos==1)
		delete_at_begin();
	else 
	{
		struct node  *temp,*t,*l;
		int i=1;
		l = start;	
		temp=start;
		while(i<pos-1 && temp!=NULL)
		{
			temp=temp->next;
			i++;
		}
		if(temp==NULL)
		{
			printf("Invalid position");
		}
		else
		{
			t = temp->next;
			temp->next = t->next;
			t->next->prev = temp;
			free(t);
		}
	}
}

