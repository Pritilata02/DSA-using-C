#include<stdio.h>
int main()
{
	int i,top,flag=0;
	char temp,stack[20],str[20];
	printf("enter to check if paranthesis is balanced or not :" );
	scanf("%s",& str);
	top = -1;
	for(i=0;str[i]!='\0';i++)
	{

		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
		{
			stack[++top]= str[i];
		}
		else if(str[i]=='}' || str[i]==')' || str[i]==']')
		{
			if(top==-1)
			{

				flag=1;
				break;
			}
			temp = stack[top--];
			if((temp =='(' && str [i]==')') || (temp =='['&& str [i]==']') || (temp =='{'&& str [i]=='}'))
			{
				continue;
			}
			else
			{
				printf("ehtoewh");
				flag = 1;
				break;
			}
		}
		else
		{
			continue;
		}
	}	
	if(top==-1 && flag == 0)
	{
		printf("the problem is balanced");
	}
	else 
	{
		printf("the problem is not balanced");
	}	


}
