#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
int top = -1,count = 0;
char temp[max];
char output[max];
void push(char t)
{
    if (top==(max-1))
	{
        printf("Stack Overflow\n");
    }
    else
	{
        temp[++top]=t;
    }
}
char pop()
{
    if (top==-1) 
	{
        printf("Stack Underflow\n");
    }
    else{
        return temp[top--];
    }
}

int main()
{
    char str[1000];
    int i,length;
    printf("Enter the String you want to be reversed:\n");
    gets(str);
    length=strlen(str);
    for(i=0;i<length;i++)
	{
        push(str[i]);
    }
    for(i=0;i<length;i++)
	{
        output[i] = pop();
    }
    output[i] = '\0';
	puts(output);
    printf("\n");
    return 0;
}

