#include<stdio.h>
int isTriangle(int,int,int);
int main()
{
	int arr[100];
	int i,j,k,n,count=0;
	printf("Enter the number of  elements in the array:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("Element %d :",i+1);
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(isTriangle(arr[i],arr[j],arr[k]))
					count++;
			}
		}
	}
	
	printf("the number of triangle possile is: %d",count);
	
}
int isTriangle(int n1,int n2, int n3)
{
	if(n1+n2>n3 && n2+n3>n1 && n1+n3>n2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}





