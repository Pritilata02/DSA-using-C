#include<stdio.h>
#include<stdlib.h>
struct node
{
	float coef;
	int ex;
	struct node *link;
};
struct node *start1,*start2,*start3;
struct node* create_node(struct node *s,int e,float c)
{
	struct node *temp,*new;
	new=(struct node*)malloc(sizeof(struct node));
	new->coef = c;
	new->ex = e;
	temp = s;
	if(temp==NULL)
	{
		s = new;
		new->link = NULL;
	}
	else
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=new;
		new->link=NULL;
	}
	return s;
}
void polynomialAddition()
{
	struct node *t1,*t2;
	t1=start1;
	t2=start2;
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->ex==t2->ex)
		{
			start3 = create_node(start3,t1->ex,t1->coef+t2->coef);
			t1=t1->link;
			t2=t2->link;
		}
		else if(t1->ex>t2->ex)
		{
			start3 = create_node(start3,t1->ex,t1->coef);
			t1=t1->link;
		}
		else
		{
			start3 = create_node(start3,t2->ex,t2->coef);
			t2=t2->link;
		}
	}
	while(t1!=NULL)
	{
		create_node(start3,t1->ex,t1->coef);
		t1=t1->link;
	}
	while(t2!=NULL)
	{
		create_node(start3,t2->ex,t2->coef);
		t2=t2->link;
	}
	
}
void display(struct node *s)
{
	struct node *t;
	t=s;
	while(t!=NULL)
	{
		printf("+");
		printf("%.2fx%d",t->coef,t->ex);
		t = t->link;
	}
	printf(" = 0\n");
}
int main()
{
	int ex,ch,i,n;
	float coef;

	printf("Enter 1 to create the 1st polynomial\n");
	printf("Enter 2 to create the 2nd polynomial\n");
	
	printf("Enter 3 for addion of the polynomial\n");
	printf("Enter 4 to display the result\n");
	printf("Enter 5 to display the 1st polynomial\n");
	printf("Enter 6 to display the 2nd polynomial\n");
	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				n = 0;  
				printf("Enter the number of terms : ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("Enter exponent value : ");
					scanf("%d",&ex);
					printf("Enter coefficient value : ");
					scanf("%f",&coef);
					start1 = create_node(start1,ex,coef);
				}
				break;
			case 2:
				n = 0;
				printf("Enter the number of terms : ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("Enter exponent value : ");
					scanf("%d",&ex);
					printf("Enter coefficient value : ");
					scanf("%f",&coef);
					start2 = create_node(start2,ex,coef);
				}
				break;
			case 3:
				polynomialAddition();
				break;
			case 4:
				display(start3);
				break;
			case 5:
				display(start1);
				break;
			case 6:
				display(start2);
				break;
			default:
				printf("invalid choice\n");
				
		}
	}
}







