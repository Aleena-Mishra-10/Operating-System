#include<stdio.h>
void find_avg(int processes[],int n,int bt[],int at[]);
void findwaitingtime(int processes[],int n,int bt[],int wt[],int at[]);
void findturnaroundtime(int processes[],int n,int bt[],int wt[],int tat[]);
int main()
{
	int processes[]={1,2,3};
	int n=3;
	int arrival_time[]={0,3,6};
	int burst_time[]={10,5,8};
	find_avg(processes,n,burst_time,arrival_time);
	return 0;
}
void find_avg(int processes[],int n,int bt[],int at[])
{
	int wt[n],tat[n],total_wt=0,total_tat=0,i,comp_time=0;
	findwaitingtime(processes,n,bt,wt,at);
	findturnaroundtime(processes,n,bt,wt,tat);
	printf("processes\tburst time\t arrival time\twaiting time\tturn around time\t completion time\n");
	for(i=0;i<n;i++)
	{
		total_tat+=tat[i];
		total_wt+=wt[i];
		comp_time=tat[i]+wt[i];
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),bt[i],at[i],wt[i],tat[i],comp_time);
	}
	printf("average waiting time:%f",total_wt/n);
	printf("average turn around  time:%f",total_tat/n);
}
void findwaitingtime(int processes[],int n,int bt[],int wt[],int at[])
{
	wt[0]=0;
	int service_time[n],i;
	service_time[0]=0;
	for(i=1;i<n;i++)
	{
		service_time[i]=service_time[i-1]+bt[i-1];
		wt[i]=service_time[i]-at[i];
		if(wt[i]<0)
		{
			wt[i]=0;
		}
	}
}
void findturnaroundtime(int processes[],int n,int bt[],int wt[],int tat[])
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
}
