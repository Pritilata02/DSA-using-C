#include<stdio.h>
#define MAX 5
int queue[MAX],start=-1,end=-1;
void insert();
void delete();
void display();
int main()
{
	int n;
	printf("Enter 1 to insert an element \n");
	printf("Enter 2 to delete an element \n");
	printf("Enter 3 to display\n");
	printf("Enter 4 to exit\n");

	while(1)
	{
		printf("\nEnter a number : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			default:
				printf("Invalid Choice \n");
				
				
		}
	}
}
void insert()
{
	int e;
	if(end==MAX-1)
	{
		printf("Overflow \n");

	}
	else{
		if(start==-1)
		{
			start++;
		}
		printf("Enter an Element :\n");
		scanf("%d",&e);
		end++;
		queue[end]=e;
		
	}
}
void delete()
{
	if(start==-1||start>end)
	{
		printf("\nUnderflow");
	}
	else{
		printf("\nDeleted:%d\n",queue[start]);
		start++;
	}
}
void display()
{
	int i;
	if((start == -1)||(start>end))
	{
		printf("\nThe Queue is Empty ");
		
	}
	else
	{
		printf("Elements : ");
		for(i=start;i<=end;i++)
		{
			printf("\n %d ",queue[i]);
		}
	}
}
