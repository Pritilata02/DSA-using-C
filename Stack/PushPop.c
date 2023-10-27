#include <stdio.h>
#define Max 5
int top=-1;
int stk[Max];
int temp,n;
int main()
{
	int c;
		printf("Enter 1 to push an element\n");
		printf("Enter 2 to pop an element\n");
		printf("Enter 3 to display the stack\n");
		printf("Enter 4 to exit\n");
	while(1)
	{	printf("Enter your choice:");
		scanf("%d",&c);
		switch (c)
		{
			case 1:
				printf("enter the element\n");
				scanf("%d",&n);
				push(n);
				break;
		    case 2:
		    	temp=pop();
		    	if(temp!=-123478)
		    	{
		    		printf("%d is poped\n",temp);
		   		}
		    	break;
			case 3:
				display();
				break;
			default :
				printf("Invalid Choice\n");
		}
	}
}
int isEmpty()
{
	return top==-1;
}
int isFull()
{
	return top==Max-1;
}
void push(int e)
{
	if(isFull())
	{
		printf("Stack overflow\n");
		
	}
	else
	{
		stk[++top]=e;	
	}
}
int pop()
{
	int temp;
	if(isEmpty())
	{
		printf("Stack underflow\n");
		return -12345678;
	}
	else
	{
		return stk [top--];
	}
}
void display()
{
	int i;
	printf("The current stack is:\n");
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stk[i]);
	}
}
