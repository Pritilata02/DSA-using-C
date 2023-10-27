#include<stdio.h>
#define MAX 5
int queue[MAX],start=-1,end=-1;
void insert();
void deletee();
void display();
int main()
{
	int n,m;
	printf("Enter 1 to insert  an element \n");
	printf("Enter 2 to delete an  element \n");
	printf("Enter 3 to display\n");
	printf("Enter 4 to exit\n");

	while(1)
	{
		printf("\nEnter a number : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the element to insert : ");  
        		scanf("%d", &m);  
				insert(m);
				break;
			case 2:
				deletee();
				break;
			case 3:
				display();
				break;
			default:
				printf("invalid choice \n");
				
				
		}
	}
}
void insert(int element) 
{
	if(start==-1&&end==-1)   
    {  
        start=0;  
        end=0;  
        queue[end]=element;  
    }  
    else if((end+1)%MAX==start)
    {  
        printf("\nQueue is overflow..");  
    }  
    else  
    {  
        end=(end+1)%MAX;   
        queue[end]=element; 
    }  
}
void deletee()
{  
	if((start==-1)&&(end==-1)) 
    {  
        printf("\nQueue is underflow..");  
    }  
 	else if(start==end)  
	{	  
   		printf("\nThe deleted element is %d",queue[start]);  
   		start=-1;  
   		end=-1;  
	}   
	else  
	{  
    	printf("\nThe deleted element is %d",queue[start]);  
   		start=(start+1)%MAX;  
	}    
}
void display() 
{
  	int i=start;  
    if(start==-1&&end==-1)  
    {  
        printf("\n Queue is empty..");  
    }  
    else  
    {  
        printf("\nElements of the Queue are :");
		for(i=start;i<=end;i++)    
       {  
	    	printf("%d ",queue[i]);  
       }  
    }  
}
