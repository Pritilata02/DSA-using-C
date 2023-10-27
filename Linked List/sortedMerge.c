#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void insert_at_begin(int);
void insert_at_any_position(int,int);
void insert_at_end(int);
void display();
void display_sec();
void insert_at_begin_sec(int);
void inser_at_any_position_sec(int,int);
void insert_at_end_sec(int);
void sortedMerge();
void displayMerge();
struct node *start = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
int main()
{
	int a,pos,el;
	printf("Enter the elements in the 1st Linked list\n");
	printf("Enter 1 to insert an element at the begining \n" );
	printf("Enter 2 to insert an Element at the end \n" );
	printf("Enter 3 to insert an element at any position \n" );
	printf("Enter 4 to display the 1st linked list\n\n");
	printf("Enter the elements in the 2nd Linked list\n");
	printf("Enter 5 to insert an element at the begining \n" );
	printf("Enter 6 to insert an Element at the end \n" );
	printf("Enter 7 to insert an element at any position \n" );
	printf("Enter 8 to display the 2nd linked list\n\n");
	printf("Enter 9 to merge two linked list and display\n\n");
	while(1)
	{
		printf("\nEnter the choice: ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("Enter the element : ");
				scanf("%d",&el);
				insert_at_begin(el);		
				break;
			case 2:
				printf("Enter the element : ");
				scanf("%d",&el);
				printf("Enter the position : ");
				scanf("%d",&pos);
				insert_at_any_position(el,pos);
				break;
			case 3:
				printf("Enter the element : ");
				scanf("%d",&el);
				insert_at_end(el);	
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Enter the element : ");
				scanf("%d",&el);
				insert_at_begin_sec(el);		
				break;
			case 6:
				printf("Enter the element : ");
				scanf("%d",&el);
				printf("Enter the position : ");
				scanf("%d",&pos);
				insert_at_any_position_sec(el,pos);
				break;
			case 7:
				printf("Enter the element : ");
				scanf("%d",&el);
				insert_at_end_sec(el);	
				break;
			case 8:
				display_sec();
				break;
			case 9:
				sortedMerge();
				displayMerge();				
				break;
			default:
				printf("Invalid choice \n");
		}
	}
}
void insert_at_begin(int el)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=el;
	temp->link=start;
	start=temp;
}
void insert_at_end(int el)
{
	struct node *temp,*i;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=el;
	temp->link=NULL;
	i=start;
	while(i->link!=NULL)
	{
		i=i->link;
	}
	i->link=temp;
}

void insert_at_any_position(int el,int pos)
{
	if(pos<=0)
		printf("Not possible\n");
	else if(pos==1)
		insert_at_begin(el);
	else
	{
		int i=1;
		struct node *temp,*t;
		t=start;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=el;
		while(i<pos-1 && t !=NULL)
		{
			t=t->link;
			i++;
		}
		
		if(t==NULL)
			printf("Invalid position.");
		else
		{
			temp->link=t->link;
			t->link=temp;
		}
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
void display_sec()
{
	struct node *j;
	j=start2;
	while(j!=NULL)
	{
		printf("%d ->",j->data);
		j=j->link;
	}
	printf("NULL\n");
}
void insert_at_begin_sec(int el)
{
	struct node *temp2;
	temp2 = (struct node*)malloc(sizeof(struct node));
	temp2->data=el;
	temp2->link=start2;
	start2=temp2;
}
void insert_at_end_sec(int el)
{
	struct node *temp2,*i;
	temp2 = (struct node*)malloc(sizeof(struct node));
	temp2->data=el;
	temp2->link=NULL;
	i=start2;
	while(i->link!=NULL)
	{
		i=i->link;
	}
	i->link=temp2;
}
void insert_at_any_position_sec(int el,int pos)
{
	if(pos<=0)
		printf("Not possible\n");
	else if(pos==1)
		insert_at_begin_sec(el);
	else
	{
		int i=1;
		struct node *temp2,*t;
		t=start2;
		temp2=(struct node*)malloc(sizeof(struct node));
		temp2->data=el;
		while(i<pos-1 && t !=NULL)
		{
			t=t->link;
			i++;
		}
		
		if(t==NULL)
			printf("Invalid position.");
		else
		{
			temp2->link=t->link;
			t->link=temp2;
		}
	}
}
void sortedMerge()
{ 
	struct node *i,*j,*temp;
	temp=start3;
	i=start;
	j=start2;
	while(i!=NULL && j!=NULL)
	{
		if(i->data==j->data)
		{
			temp->data=i->data;
			i=i->link;
			j=j->link;	
		}
		else if(i->data < j->data)
		{
			temp->data=i->data;
			i=i->link;
		}
		else if(i->data > j->data)
		{
			temp->data=j->data;
			j=j->link;
		}
		temp=temp->link;
		
	}
	if (i!= NULL)
        temp->link = i;
    if (j!= NULL)
        temp->link = j;
	
}
void displayMerge()
{
    struct node *k;
	k=start2;
	while(k!=NULL)
	{
		printf("%d ->",k->data);
		k=k->link;
	}
	printf("NULL\n");
}












