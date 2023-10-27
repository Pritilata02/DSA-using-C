 #include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
	 
};
void insert_at_begin(int);
void insert_at_end(int);
void display();
void insert_at_any_pos(int,int);
void node_count();
void delete_at_begin();
void delete_at_end();
void delete_at_any_pos(int);
void delete_any_element(int);
void insert_after_el(int,int);
void insert_before_el(int,int);
void search_of_el(int); 
void sort();
void unique();
void frequency(int);
void duplicate(int);
struct node *start =NULL;
int main()
{
	int ch,el,pos;
	printf("Enter 1 to insert an element at the begining \n\n" );
	printf("Enter 2 to insert an Element at the end \n\n" );
	printf("Enter 3 to insert an element at any position \n\n" );
	printf("Enter 4 to delete an element at begining \n\n");
	printf("Enter 5 to delete an element at the end\n\n");
	printf("Enter 6 to insert an element after any element\n\n");
	printf("Enter 7 to insert an element before any element\n\n");
	printf("Enter 8 to search an element:\n\n");
	printf("Enter 9 to sort the linked list\n\n");
	printf("Enter 10 to delete an element at any position\n\n");
	printf("Enter 11 to display the node count\n\n");
	printf("Enter 12 to display\n\n");
	printf("Enter 13 to find unique element\n\n");
	printf("Enter 14 to delete any element\n\n");
	printf("Enter 15 to find frequency of an element\n\n");
	printf("Enter 16 to find duplicate element\n\n");
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
				delete_at_begin();
				break;
			case 5:
				delete_at_end();
				break;
			case 6:
				printf("Enter an Element :");
				scanf("%d",&el);
				printf("Enter the number after which you want to insert :");
				scanf("%d",&pos);
				insert_after_el(el,pos);
				break;
			case 7:
				printf("Enter an Element :");
				scanf("%d",&el);
				printf("Enter the number before which you want to insert :");
				scanf("%d",&pos);
				insert_before_el(pos,el);
				break;
			case 8:
				printf("Enter an Element :");
				scanf("%d",&el);
				search_of_el( el);
				break;
			case 9:
				sort();
				break;
			case 10:
				printf("Enter any Position :");
				scanf("%d",&pos);
				delete_at_any_pos(pos);
				break;
			case 11:
				node_count();
				break;
			case 12:
				display();
				break;
			case 13:
				printf("Enter an Element :");
				scanf("%d",&el);
				unique(el);
				break;
			case 14:
				printf("Enter an Element :");
				scanf("%d",&el);
				delete_any_element(el);
				break;
			case 15:
				printf("Enter an Element :");
				scanf("%d",&el);
				frequency(el);
				break;
			case 16:
				printf("Enter an Element :");
				scanf("%d",&el);
				duplicate(el);
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
void node_count()
{
	
	int count = 0;
	struct node *i =NULL;
	i=start;
	while(i!=NULL)
	{
		count++;
		i=i->link;
	}
	printf("Count of Node: %d\n",count);
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
void delete_at_begin()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("No List\n");
	}
	else
	{
	temp=start;
	start=start->link;
	free(temp);
	}
}
void delete_at_end()
{
	struct node *temp,*i,*t;
	if(start->link==NULL)
	{
		t=start;
		start=NULL;
		free(t);
	}
	else
	{
	i=start;
	while(i->link->link!=NULL)
	{
		i=i->link;
	}

	temp=i->link;
	i->link=NULL;
	free(temp);
	}
}
void delete_at_any_pos(int pos)
{
	if(pos==0)
		printf("not possible\n");
	else if(pos==1)
		delete_at_begin();
	else
	{
		struct node  *temp,*t;
		temp= (struct node*)malloc(sizeof(struct node));
		int i=1;
		temp=start;
		while(i<pos-1 && temp != NULL)
		{
			temp=temp->link;
			i++;
		}
		if(temp==NULL)
		{
			printf("Invalid position\n");
		}
		else
		{
			t=temp->link;
		    temp->link=t->link;	
			free(t);	    
		}
		
	}
}
void delete_any_element(int el)
{
	struct node  *temp,*t;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=start;
	if(start->data==el)
	{
		delete_at_begin();
	}
	else
	{
		while(temp->link!=NULL)
		{
			if(temp->link->data==el)
			{
				break;
			}
		}
		t=temp->link;
		temp->link =temp->link->link;
		free(t);
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
void search_of_el(int el)
{
	struct node *temp,*p,*q;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=el;
	p=start;
	while(p!=NULL)
	{
		if(p->data==temp->data)
		{
			printf("element found\n");
		}
		else
		{
			printf("element not found\n");
		}
		p=p->link;
	}
}

void sort()
{
	struct node *i,*j;
	int temp;
	
	for(i=start;i->link!=NULL;i=i->link)
	{
		for(j=i->link;j!=NULL;j=j->link)
		{
			if(i->data > j->data)
			{
				temp=i->data;
				i->data = j->data;
				j->data=temp;
			}
		}
	}
}
void unique(el)
{
	struct node *temp;
	int count=0;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=start;
	while(temp!=NULL)
	{
		if(temp->data==el)
		{
			count++;
		}
		temp=temp->link;
	}
		if(count==1)
		{
			printf("unique element\n");
		}
		else
		{
			printf("Not an unique elelment\n");
		}
}
void duplicate(int el)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	int duplicate=0;
	temp=start;
	while(temp!=NULL)
	{
		if(temp->data==el)
		{
			duplicate++;
		}
		temp=temp->link;
	}
	if(duplicate>1)
	{
		printf("Duplicate of %d founded\n",el);
	}
	else
	{
		printf("Duplicate of %d not founded\n",el);	
	}
		
}
void frequency(int el)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	int frequency=0;
	temp=start;
	while(temp!=NULL)
	{
		if(temp->data==el)
		{
			frequency++;
		}
		temp=temp->link;
	}
	printf("The frequency of %d is:%d\n",el,frequency);
}

