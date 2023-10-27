#include <stdio.h>
int fact(int);
int main()
{
    int n;
    printf("Enter a  number: \n");
    scanf("%d",&n);

    if(n<0)
    {
        printf("factorial doesn't exist\n");
    }
	else
	{
    	printf("Factorial of %d is: %d",n,fact(n));
	}
}
int fact(int n)
{
    if (n==1||n==0)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

