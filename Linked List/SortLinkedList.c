   #include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
	 
};
void insert_at_begin(int);
void insert_at_end(int);
void insert_at_any_pos(int,int);
void insert_after_el(int,int);
void insert_before_el(int,int);
void sort();
void display();
struct node *start =NULL;
struct node *start2 =NULL;

int main()
{
	int ch,el,pos;
	printf("Enter 1 to insert an element at the begining \n\n");
	printf("Enter 2 to insert an Element at the end \n\n");
	printf("Enter 3 to insert an element at any position \n\n");
	printf("Enter 4 to insert an element after any element\n\n");
	printf("Enter 5 to insert an element before any element\n\n");
	printf("Enter 6 to sort the linked list\n\n");
	printf("Enter 7 to display\n\n");
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
				printf("Enter an Element :");
				scanf("%d",&el);
				insert_at_end(el);
				break;
			case 3:
				printf("Enter an Element :");
				scanf("%d",&el);
				printf("Enter any Position :");
				scanf("%d",&pos);
				insert_at_any_pos(el,pos);
				break;
			case 4:
				printf("Enter an Element :");
				scanf("%d",&el);
				printf("Enter the number after which you want to insert :");
				scanf("%d",&pos);
				insert_after_el(el,pos);
				break;
			case 5:
				printf("Enter an Element :");
				scanf("%d",&el);
				printf("Enter the number before which you want to insert :");
				scanf("%d",&pos);
				insert_before_el(pos,el);
				break;
			case 6:
				sort();
				break;
			case 7:
				display();
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
void insert_at_end(int el)
{
	struct node *temp,*i;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=el;
	temp->link=NULL;
	i=start;
	while(i->link!=NULL)
	{
		i=i->link;
	}
	i->link=temp;
}
void insert_at_any_pos(int el,int pos)
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
void insert_after_el(int el,int pos)
{
	struct node *temp,*p,*q;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=el;
	p=start;
	while(p!=NULL)
	{
		if(p->data==pos)
		{
			q=p->link;
			p->link=temp;
			temp->link=q;
			
		}
		p=p->link;
	}
}

void insert_before_el(int key,int el)
{
	struct node *t,*temp;
	t=(struct node*)malloc(sizeof(struct node));
	temp=start;
	while(temp->link!=NULL)
	{
		if(start->data==key)
		{
			insert_at_begin(el);
			break;
		}
		else if(temp->link->data==key)
		{
			t->data=el;
			t->link=temp->link;
			temp->link=t;
			break;
	
		}
		
		temp=temp->link;
		
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

void sort()
{
	struct node *new,*temp,*temp2;
	if(start!=NULL)
	{
		new=(struct node*)malloc(sizeof(struct node));
		start2=new;
		new->data=start->data;
		new->link=NULL;
	}
	temp=start->link;
	while(temp!=NULL)
	{
		temp2=start2;
		if(temp2->link==NULL)
		{
			if(temp->data<temp2->data)
			{
				new=(struct node*)malloc(sizeof(struct node));
				new->data=temp->data;
				new->link=start2;
				start2=new;
			}
			else
			{
				new=(struct node*)malloc(sizeof(struct node));
				new->data=temp->data;
				new->link=NULL;
				temp2->link=new;
			}
		}
		else if(temp->data<start2->data)
		{
			new=(struct node*)malloc(sizeof(struct node));
			new->data=temp->data;
			new->link=start2;
			start2=new;
		}
		else
		{
			while(temp2->link!=NULL && temp->data > temp2->link->data)
			{
				temp2=temp2->link;
			}
				new=(struct node*)malloc(sizeof(struct node));
				new->data=temp->data;
				new->link=temp2->data;
				temp2->link=new;	
		}
		temp=temp->link;
	}
}



























