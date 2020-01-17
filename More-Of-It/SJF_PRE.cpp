#include<stdio.h>
#include<stdlib.h>

struct data{
	int id;
	int arrival_time;
	int burst_time;
	int wt;
	int tt;
};

struct gant{
	int id;
	struct gant *next;
};

//Global Variables
int n,time_quantum;
float avg_wt=0.0,avg_tt=0.0;
struct gant *head = NULL;

void sort_array(struct data *a,int index, int type)
{
	if(type == 1)
		for(register int i =1;i<=index;i++)
		{
			struct data temp = a[i];
			int j = i-1;
			while(j>=0 && temp.arrival_time<a[j].arrival_time)
			{
				a[j+1]=a[j];
				j--;
			}
			a[j+1] = temp; 
		}
	else if(type == 2)
	{
		for(register int i =1;i<=index;i++)
		{
			struct data temp = a[i];
			int j = i-1;
			while(j>=0 && temp.burst_time<a[j].burst_time)
			{
				a[j+1]=a[j];
				j--;
			}
			a[j+1] = temp; 
		}
	}
}

void check_index(struct data *a,int time)
{
	int count=0;
	for(register int i=0;i<n;i++)
	{
		if(time>=a[i].arrival_time)
		{
			count++;
			continue;
		}
		
		break;
	}
	sort_array(a,count-1,2);
}

void activate(struct data *a, int time)
{
	static int count =0;
	if(count == n)
		return;
	for(register int i=0;i<n;i++)
	{
		if(a[i].arrival_time<=time && a[i].tt<0)
		{
			a[i].tt=0;
			a[i].wt=0;
			count++;
		}
	}
}

void update_time(struct data *a , int index)
{
	for(register int i =0;i<n;i++)
	{
		if(a[i].wt<0 || i == index || a[i].burst_time<=0)
			continue;
		a[i].wt++;
	}
}

struct gant* make_gantt(struct gant *head, int id)
{
	if(head == NULL)
	{
		struct gant *newptr = (struct gant*)malloc(sizeof(struct gant));
		newptr->next = NULL;
		newptr->id = id;
		head = newptr;
		return newptr;
	}
	else
	{
		struct gant *ptr = head;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		if(ptr->id == id)
			return head;
		else
		{
			struct gant *newptr = (struct gant*)malloc(sizeof(struct gant));
			newptr->next = NULL;
			newptr->id = id;
			ptr->next = newptr;
			ptr = newptr;
			return head;
		}
	}
}

void premptive(struct data *rr)
{
	sort_array(rr,n-1,1);
	
	
	printf("Process 	  Arrival Time 		Burst Time\n");
	for(register int i=0;i<n;i++)
	{
		printf("P%d 		%d 			%d\n",rr[i].id,rr[i].arrival_time,rr[i].burst_time);
	}
	
	int complete_time = 0;
	for(register int i =0;1;)
	{
		activate(rr, complete_time);
		
		if(complete_time<n)
			check_index(rr,complete_time);
		else
			sort_array(rr,n-1,2);
		
		if(complete_time<rr[i].arrival_time)
		{
			complete_time+=1;
			continue;
		}
		head = make_gantt(head,rr[i].id);
		rr[i].burst_time --;
		if(rr[i].burst_time<=0)
		{
			complete_time ++;
			rr[i].tt+=complete_time - rr[i].arrival_time;
			rr[i].burst_time = 0;
			update_time(rr, i);
			i++;
		}
		else{
			update_time(rr, i);
			complete_time++;
		}
		if(i==n)
			break;
		
		if(complete_time<n)
			check_index(rr,complete_time);
		else
			sort_array(rr,n-1,2);
			
	}
}

int main()
{
	printf("Enter The Number Of Process: ");
	scanf("%d",&n);
	struct data rr[n];
	for(register int i=0;i<n;i++)
	{
		rr[i].id = i+1;
		printf("\nEnter the arrival_time of %d Process: ",(i+1));
		scanf("%d",&rr[i].arrival_time);
		printf("Enter the burst_time of %d Process: ",(i+1));
		scanf("%d",&rr[i].burst_time);
		rr[i].wt = -1;
		rr[i].tt = -1;
	}
	
	premptive(rr);
	printf("\n************************* Gantt Chart ************************\n");
	while(head!=NULL)
	{
		printf("P%d ",head->id);
		head=head->next;
	}
	printf("\n**************************************************************\n");
	printf("\nProcess 	  Waiting Time 		Turn Arround Time\n");
	for(register int i=0;i<n;i++)
	{
		printf("P%d	 	%d 		%d\n",rr[i].id,rr[i].wt,rr[i].tt);
		avg_wt+=rr[i].wt;
		avg_tt+=rr[i].tt;
	}
	printf("\nAverage Waiting Time is: %f\nAverage Turn Arround Time: %f",(avg_wt/n),(avg_tt/n));
}
