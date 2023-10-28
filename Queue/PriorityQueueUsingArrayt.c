#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct priorityqueue
{
	int data;	
	int priority;
}pq[MAX];
int start=-1,end=-1;
void insert(int,int);
void display();
int main()	
{
	int n,data,p;
	printf("Enter 1 to insert element and it's priority \n");
	printf("Enter 2 to display the queue \n");
	
	while(1)
	{
		printf("\nEnter a Choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the element : ");
				scanf("%d",&data);
				printf("Enter its priority : ");
				scanf("%d",&p);
				insert(data,p);		
				break;
			case 2:
				display();
				break;
			default :
				printf("Invalid choice");
			
		}
	}
}

void insert(int data,int priority)
{
		int i,j;
		if(start==0 && end ==MAX-1)
		{
			printf("Queue is full");
			
		}
		else if(start==-1)
		{
			start=0;
			end=0;
			pq[end].data=data;
			pq[end].priority=priority;
		}
		else
		{
			if(start==MAX-1)
			{
				for(i=start;i<=end;i++)
				{
					pq[i-1]=pq[i];
					start--;
					end--;
				}
			}
			for(i=end;i>=start;i--)
			{
				if(pq[i].priority>=priority)
				{
					break;
				}
			}
			j=i+1;
			
			for(i=end;i>=j;i--)
			{
				pq[i+1]=pq[i];
				
			}
			pq[j].data=data;
			pq[j].priority=priority;
			end++;
		}				
}
void display()
{
	int i;
	if(start==-1)
	{
		printf("Queue is empty");
		
	}
	else
	{
		for(i=start;i<=end;i++)
		{
			printf("%d  ",pq[i].data);
		}
	}
}














