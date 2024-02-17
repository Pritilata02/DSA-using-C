#include<stdio.h>

void merge(int arr[],int s,int mid,int e);
void merge_sort(int arr[],int s,int e);

int main()
{
    int i,n,arr[100];
	printf("Enter the total number of elements : ");
	scanf("%d",&n);
	printf("Enter the numbers : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}	
    merge_sort(arr,0,n-1);
    printf("After Merge Sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void merge_sort(int arr[],int s,int e)
{
    if(e>s)
    {
        int mid=(s+e)/2;
        merge_sort(arr,s,mid);
        merge_sort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
}
void merge(int arr[],int s,int mid,int e)
{
    int i=s,j=mid+1,k=0;
    int temp[e-s+1];
    while (i<=mid && j<=e)
    {
        if (arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }

    while (i<=mid)
    {
        temp[k++]=arr[i++];
    }

    while (j<=e)
    {
        temp[k++]=arr[j++];
    }

    i = 0;
    j = s;
    while (i<k)
    {
        arr[j++]=temp[i++];
    }
}

