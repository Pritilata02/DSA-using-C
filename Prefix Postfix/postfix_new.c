#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int top = -1;
int stk[MAX];

int isfull()
{
	return top == MAX-1;
}

int isempty()
{
	return top==-1;
}

void push(int e)
{
	if(isfull())
	{
		printf("Stack overflow!!");
		exit(0);
	}
	stk[++top] = e;
}

int pop()
{
	if(isempty())
	{
		printf("Stack underflow!!");
		exit(0);
	}
	return stk[top--];
}

int isOperator(char e)
{
	return e == '+' || e == '-' || e == '*' || e == '/'; 
}

int isDigit(char e)
{
	return (e>='0' && e<='9');
}
int evaluate(char o,int a,int b)
{
	if(o == '+')
		return a+b;
	else if(o == '-')
		return a-b;
	else if(o == '*')
		return a*b;
	else if(o == '/')
		return a/b;
}

int main()
{
	int i,a,b,result;
	char post[MAX];
	
	printf("Enter a postfix expression: ");
	gets(post);
	
	for(i=0;post[i]!='\0';i++)
	{
		if(post[i] == ' ')
			continue;
		if(isdigit(post[i]))
		{
			push(post[i]-'0');
		}
		else if(isOperator(post[i]))
		{
			b = pop();
			a = pop();
			push(evaluate(post[i],a,b));
			
		}		
	
	}

	result=pop();
	
	printf("\nThe postfix evaluation is: %d\n",result);
	
}
