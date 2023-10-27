#include<stdio.h>
int is_strong(int);
int count(int);
int fact(int);
int main()
{
	int n;
	printf("Enter a Number:");
	scanf("%d",&n);
	if(is_strong(n))
	{
		printf("Yes");	
	}
	else
	{
		printf("No");
	}
}
int fact(int n)
{
	int  i, fact=1;
   for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    return fact;
}
int is_strong(int n)
{
	int temp,sum;
	sum=0;temp=n;
	while(n>0)
	{
		sum+= fact(n%10);
		n/=10;
	}
	return temp==sum;
}
