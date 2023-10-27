#include<stdio.h>
int lcm(int,int);
int main()
{
	int a,b,l;
	
	printf("Enter any 2 numbers : ");
	scanf("%d%d",&a,&b);
	if(a>b)
        l=lcm(b,a);
    else
        l=lcm(a,b);
        
	printf("LCM of %d and %d is : %d",a,b,l);
}
int lcm(int a,int b)
{
	int n=0;
	n=n+b;
	if(n%a==0 && n%b == 0)
	{
		return n;
	}
	else if(a%b!=0 || b%a!=0)
	{
		return a*b;
	}
	else
	{
		return lcm(a,b);	
	}
}
