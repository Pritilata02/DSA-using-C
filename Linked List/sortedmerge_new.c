#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *new;
struct node *create(struct node *);
void display(struct node *);
struct node *sortedMerge(struct node *,struct node *);
int main()
{
	struct node *a=NULL,*b=NULL;
	a=create(a);
	printf("First linked List is :\n");
	display(a);
	b=create(b);
	printf("Second linkedList is :\n");
	display(b);
	a=sortedMerge(a,b);
	printf("Merged linked list is:\n");
	display(a);
}
struct node *create(struct node *a)
{
	struct node *temp,*q;
	int n,m,i;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("Enter the elements\n");
	scanf("%d",&m);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=m;
	temp->link=NULL;
	if(a==NULL)
	{
		a=temp;
	}
	else
	{
		q=a;
		while(q->link!=NULL)
		{
			q=q->link;
		}
			q->link=temp;
		}
		}
		return a;
}
void display(struct node *a)
{
	struct node *q;
	if(a==NULL)
	{
	printf("List is empty\n");
	}
	else
	{
		q=a;
		while(q!=NULL)
		{
			printf("%d->",q->data);
			q=q->link;
		}
			printf("NULL\n");
		}
}
struct node *sortedMerge(struct node *a,struct node *b )
{ 
	struct node *i,*j,*temp;
	temp=new;
	i=a;
	j=b;
	temp=(struct node*)malloc(sizeof(struct node));
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
		temp=NULL;
	}
	if (i!= NULL)
        temp->link = i;
        
    if (j!= NULL)
        temp->link = j;
        
return a;	
}
