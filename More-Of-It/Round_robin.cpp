#include<stdio.h>

struct data{
	int id;
	int arrival_time;
	int burst_time;
	int wt;
	int tt;
	int c;
};

//Global Variables
int n,time_quantum;
float avg_wt=0.0,avg_tt=0.0;

//sort array according to arrival time
void sort_array(struct data *a)
{
	for(register int i =1;i<n;i++)
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
	
}

//Rotation algorithm
void rotate_array(struct data *a, int index, int end)
{
	//printf("\n rotate from %d to %d",index,(end-1));
	struct data first = a[index];
	for(register int i =index;i<end-1;i++)
	{
		a[i]=a[i+1];
	}
	if(end-1<0)
		return;
	a[end-1] = first;
}

//checking active Process
void check_index(struct data *a,int time, int index)
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
	rotate_array(a,index,count);
}

//Process Entered In The Queue
void activate(struct data *a, int time)
{
	static int cnt = 0;
	if(cnt == n)
		return;
	for(register int i=0;i<n;i++)
	{
		if(a[i].arrival_time<=time && a[i].tt<0)
		{
			a[i].tt=0;
			a[i].wt=0;
			cnt++;
		}
	}
}

//Update The Waiting Time for process
void update_time(struct data *a , int time, int index, int total_time)
{
	for(register int i =0;i<n;i++)
	{
		if(a[i].wt<0 || i == index || a[i].burst_time<=0)
			continue;
		if(a[i].wt==0 && a[i].c==0)
		{
			a[i].wt+=total_time-a[i].arrival_time;
			a[i].c = 1;
		}	
		else a[i].wt+=time;
	}
}

//Print array
void print_array(struct data *a)
{
	printf("Process 	  Arrival Time 		Burst Time\n");
	for(register int i=0;i<n;i++)
	{
		printf("P%d 		%d 			%d\n",a[i].id,a[i].arrival_time,a[i].burst_time);
	}
}

//Round robin algorithm
void round_robin(struct data *rr)
{
	sort_array(rr);
	rr[0].c = 1;		//Starting Process has already started
	print_array(rr);
	
	int complete_time = 0;
	printf("\n************************ GANTT CHART *************************\n");
	for(register int i =0;i<n;)
	{
		activate(rr, complete_time);
		//print_array(rr);	
		if(complete_time<rr[i].arrival_time)
		{
			complete_time+=1;
			continue;
		}
		printf("P%d ",rr[i].id);
		rr[i].burst_time -= time_quantum;
		if(rr[i].burst_time<=0)
		{
			complete_time += time_quantum+rr[i].burst_time;
			rr[i].tt+=complete_time-rr[i].arrival_time;

			update_time(rr,time_quantum+rr[i].burst_time, i, complete_time);
			rr[i].burst_time = 0;
			activate(rr, complete_time);
			i++;
			continue;			
		}
		else{
			complete_time += time_quantum;
			activate(rr, complete_time);
			update_time(rr,time_quantum, i, complete_time);
		}
		
		if(complete_time<n)
			check_index(rr,complete_time,i);
		else
			rotate_array(rr,i,n);
			
	}
	printf("\n**************************************************************\n");
}

int main()
{
	printf("Enter The Number Of Process: ");
	scanf("%d",&n);
	struct data rr[n];
	printf("Enter the time quantum : ");
	scanf("%d",&time_quantum);
	for(register int i=0;i<n;i++)
	{
		rr[i].id = i+1;
		printf("Enter the arrival_time of %d Process: ",(i+1));
		scanf("%d",&rr[i].arrival_time);
		printf("Enter the burst_time of %d Process: ",(i+1));
		scanf("%d",&rr[i].burst_time);
		rr[i].wt = -1;
		rr[i].tt = -1;
		rr[i].c = 0;
	}
	
	round_robin(rr);
	printf("\nProcess 	  Waiting Time 		Turn Arround Time\n");
	for(register int i=0;i<n;i++)
	{
		printf("P%d 		 %d 			%d\n",rr[i].id,rr[i].wt,rr[i].tt);
		avg_wt+=rr[i].wt;
		avg_tt+=rr[i].tt;
	}
	
	printf("Average Waiting Time Is %f\nAverage Turround Time Is %f",(avg_wt/n),(avg_tt/n));
}
