#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int Q[MAX];
int end=-1;
int start=-1;
int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        int n;
        switch (choice)
        {
            case 1:
            	printf("Enter the element to insert: ");
            	scanf("%d",&n);
            	insert(n);
            	break;
            case 2:
            	deletee();
            break;
            case 3:
            	display();
            	break;
            case 4:
            	exit(1);
            default:
            printf("Invalid choice \n");
        }
    }
}
void insert()
{
	int e1;
	if (isfull())
	{
		printf("Queue overflow");
	}
    else if(start == - 1)
    {
    	start++;
    	end ++;
    }
    else
	{
        end++;
        Q[end] = e1;
    }
}
int isfull()
{
	return end==MAX-1;
}

void deletee()
{
    if(!isempty())
    {
    	int r;
    	r=start++;
    	if(start>end)
    	{
    		start=-1;
    		end=-1;
		}
		else
		{
			printf("The queue is empty");
		}
	}
}
int isempty()
{
	return end==-1;
}
    

void display()
{
    int i;
    if (start==-1|| start>end)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is :\n");
        for (i=start;i<= end;i++)
            printf("%d ",Q[i]);
        printf("\n");
    }
}
