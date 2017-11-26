#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pr_queue
{
	char name[30];
	int size;
	int id;
	int rt;
	int pr;
	struct pr_queue* next;
}*start,*t,*q,*s;

//Defining functions for operations: priority, sjf, fcfs, display.

/*
Comparing from start node with all other nodes in the linked list.
's' is the node that is compared. 'q' is the rest of the nodes that is being compared to s. 
't' stores the previously compared q node
*/

void priority(int n)
{
	int k,j;
	int tsize,tid,trt,tpr;
	char tname[30];
	s=start;
	
	//Comparing every node.
	for(k=0;k<n-1;k++)
	{
		s=start;
			
		for(j=0;j<n-k-1;j++)
		{
			q=s->next;
			
			if((s->pr)>(q->pr))
			{
				
				//Storing all values in temp variables for swapping.

				strcpy(tname,s->name);
				tsize=s->size;
				tid=s->id;
				trt=s->rt;
				tpr=s->pr;

				//Swapping values in s and q

				strcpy(s->name,q->name);
				s->size=q->size;
				s->id=q->id;
				s->rt=q->rt;
				s->pr=q->pr;

				//Restoring temp values in q

				strcpy(q->name,tname);
				q->size=tsize;
				q->id=tid;
				q->rt=trt;
				q->pr=tpr;
			}

			s=s->next;
		
		}
	}

}

void sjf(int n)
{
	int k,j;
	int tsize,tid,trt,tpr;
	char tname[30];
	s=start;
	
	//Comparing every node.
	for(k=0;k<n-1;k++)
	{
		s=start;
			
		for(j=0;j<n-k-1;j++)
		{
			q=s->next;
			
			if((s->rt)>(q->rt))
			{
				
				//Storing all values in temp variables for swapping.

				strcpy(tname,s->name);
				tsize=s->size;
				tid=s->id;
				trt=s->rt;
				tpr=s->pr;

				//Swapping values in s and q

				strcpy(s->name,q->name);
				s->size=q->size;
				s->id=q->id;
				s->rt=q->rt;
				s->pr=q->pr;

				//Restoring temp values in q

				strcpy(q->name,tname);
				q->size=tsize;
				q->id=tid;
				q->rt=trt;
				q->pr=tpr;
			}

			s=s->next;
		
		}
	}

}


void fcfs(int n)
{
	int k,j;
	int tsize,tid,trt,tpr;
	char tname[30];
	s=start;
	
	//Comparing every node.
	for(k=0;k<n-1;k++)
	{
		s=start;
			
		for(j=0;j<n-k-1;j++)
		{
			q=s->next;
			
			if((s->id)>(q->id))
			{
				
				//Storing all values in temp variables for swapping.

				strcpy(tname,s->name);
				tsize=s->size;
				tid=s->id;
				trt=s->rt;
				tpr=s->pr;

				//Swapping values in s and q

				strcpy(s->name,q->name);
				s->size=q->size;
				s->id=q->id;
				s->rt=q->rt;
				s->pr=q->pr;

				//Restoring temp values in q

				strcpy(q->name,tname);
				q->size=tsize;
				q->id=tid;
				q->rt=trt;
				q->pr=tpr;
			}

			s=s->next;
		
		}
	}


}


void display(int n)
{
	int i;
	s=start;
	printf("\n\n\nTHE ORDER OF PROCESSES ARE:\n");
	for(i=0;i<n;i++)
	{
		puts(s->name);
		s=s->next;
	}
	printf("\n\n\n");
}


int main()
{
	int n,i;
	printf("Enter number of processes.\n");
	scanf("%d",&n);
	
	//Creating n nodes in the priority queue and data entry.
	for(i=0;i<n;i++)
	{
		s=(struct pr_queue *)malloc(sizeof(struct pr_queue));
		
		printf("\n\nEnter name of %d process:\n",i+1);
		scanf("%s",s->name);
		
		printf("Enter size of process:\n");
		scanf("%d",&s->size);
		
		printf("Enter runtime of process:\n");
		scanf("%d",&s->rt);
		
		printf("Enter priority of process between 1 to %d:\n",n);
		scanf("%d",&s->pr);
		
		s->id=i+1;
		s->next=NULL;
		
		//Checking for 1st node
		if(i==0)
		start=s;
		else
		q->next=s;
		
		q=s;
	} 
	display(n);
	//Displaying menu for process scheduling.
	while(1)
	{
		printf("\n\nMENU FOR CPU SCHEDULING:\nEnter your choice:\n");
		printf("1.PRIORITY\n2.SJF\n3.FCFS\n4.EXIT\n");
		scanf("%d",&i);
		
		//Calling function for display of process according to selection
		if(i==4)
			break;
		else
		{
			 switch(i)
			 {
				case 1:
				{
					priority(n);
					display(n);
					break;
				}

				case 2:
				{
					sjf(n);
					display(n);
					break;
				}

				case 3:
				{
					fcfs(n);
					display(n);
					break;
				}

				default:
				printf("Wrong choice entered.\nPlease try again.\n");
			}
	    }
				
	}
	
	return 0;
}