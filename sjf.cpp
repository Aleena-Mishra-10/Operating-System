#include<iostream>
using namespace std;

struct Process{
	int pid;
	int bt;
	int art;
};
void findavgTime(Process proc[],int n);
void findingWaitingTime(Process proc[],int n,int wt[]);
void findTurnAroundTime(Process proc[],int n,int wt[],int tat[]);


int main()
{
	Process proc[]= { {1,6,1} , {2,8,1} , {3,7,2} , {4,3,3}};
	int n=4;
	findavgTime(proc,n);
	return 0;
}
void findavgTime(Process proc[],int n){
	int wt[n],tat[n],total_wt=0,total_tat=0;
	findingWaitingTime(proc,n,wt);
	findTurnAroundTime(proc,n,wt,tat);
	cout<<"Process"<<"\t\t"
		<<"Burst Time"<<"\t\t"
		<<"Arrival Time"<<"\t\t"
		<<"Waiting Time"<<"\t\t"
		<<"Turn Around Time"<<endl;

	for(int i=0;i<n;i++){
		total_wt= total_wt + wt[i];
		total_tat=total_tat+tat[i];
		cout<<"\n "<<proc[i].pid<<"\t\t"<<proc[i].bt<<"\t\t\t"<<proc[i].art<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tat[i]<<endl;
	}
	cout<<"\naverage waiting time="<<float(total_wt)/float(n);
	cout<<"\naverage turnaround time"<<float(total_tat)/float(n);
	
}

void findingWaitingTime(Process proc[],int n,int wt[]){
	int rt[n];
	int complete=0 , shortest = 0 , t=0;
	int min = INT8_MAX;
	int finish_time ;
	bool check = false;
	for(int i=0;i<n;i++){
		rt[i]=proc[i].bt;
	}
	while(complete!=n){
	for(int i=0;i<n;i++){
		if((proc[i].art<=t)&&(rt[i]<min&&rt[i]>0)){
			min=rt[i];
			shortest=i;
			check=true;
		}
	}
	if(check==false){
		t++;
		continue;
	}
	rt[shortest]--;
	min=rt[shortest];
	if(min==0){
		min=INT8_MAX;
	}
	if(rt[shortest]==0){
		complete++;
		check=false;
		finish_time=t+1;
		wt[shortest]=finish_time-proc[shortest].bt-proc[shortest].art;
		if(wt[shortest<0]){
			wt[shortest]=0;
		}
	}
	t++;
	}

}

void findTurnAroundTime(Process proc[],int n,int wt[],int tat[]){
		for(int i=0;i<n;i++){
			tat[i]=proc[i].bt+wt[i];
		}
}