#include<stdio.h>
int quick_sort(int s,int e,int arr[]);
void swap(int *a,int *b);
int main() 
{
    int i,n,arr[50];
    printf("Enter the total number of elements : ");
    scanf("%d",&n);
    printf("Enter the numbers : \n");
    for (i = 0;i<n;i++) 
	{
        scanf("%d",&arr[i]);
    }
    quick_sort(0,n-1,arr);
    printf("After Quick Sorting :\n");
    for (i=0;i<n;i++) 
	{
        printf("%d ",arr[i]);
    }
}
int quick_sort(int s,int e,int arr[]) 
{
    if(s<e) 
	{
        int piv=s;
        int i=s+1;
        int j=e;
        while(i<=j) 
		{
            while(arr[i]<=arr[piv] && i<=e) 
			{
                i++;
            }
            while(arr[j]>=arr[piv] && j>s) 
			{
                j--;
            }
            if(j>i) 
			{
                swap(&arr[i],&arr[j]);
            }
        }
        swap(&arr[j],&arr[piv]);
        quick_sort(s,j-1,arr);
        quick_sort(j+1,e,arr);
    }
}
void swap(int *a,int *b) 
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
