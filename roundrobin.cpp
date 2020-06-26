#include<iostream>
using namespace std;
void findavgtime(int processes[],int burst_time[],int n,int quantum);
void findwaitingtime(int processes[],int burst_time[],int n,int quantum,int wt[]);
void findturnaroundtime(int processes[],int burst_time[],int n,int wt[],int tat[]);
int main(){
    int n=4 , quantum=2;
    int processes[]={1,2,3,4};
    int burst_time[]={4,7,5,6};
    findavgtime(processes,burst_time,n,quantum);
    return 0;
}
void findavgtime(int processes[],int burst_time[],int n,int quantum){
    int wt[n],tat[n],total_wt=0,total_tat=0;
    findwaitingtime(processes,burst_time,n,quantum,wt);
    findturnaroundtime(processes,burst_time,n,wt,tat);
    cout<<"Process"<<"\t\t"
		<<"Burst Time"<<"\t\t"
		<<"Waiting Time"<<"\t\t"
		<<"Turn Around Time"<<endl;

	for(int i=0;i<n;i++){
		total_wt= total_wt + wt[i];
		total_tat=total_tat+tat[i];
		cout<<"\n "<<processes[i]<<"\t\t"<<burst_time[i]<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tat[i]<<endl;
	}
	cout<<"\naverage waiting time="<<float(total_wt)/float(n);
	cout<<"\naverage turnaround time"<<float(total_tat)/float(n);
}
void findwaitingtime(int processes[],int burst_time[],int n,int quantum,int wt[]){
    int rm_bt[n];
    int t=0;
    for(int i=0;i<n;i++){
        rm_bt[i]=burst_time[i];
    }
    while(1){
        bool done=true;
        for(int i=0;i<n;i++){
            if(rm_bt[i]>0){
                done=false;
                if(rm_bt[i]>quantum){
                    t+=quantum;
                    rm_bt[i]=rm_bt[i]-quantum;
                }
                else{
                    t=t+rm_bt[i];
                    wt[i]=t-burst_time[i];
                    rm_bt[i]=0;
                }
            }
        }
        if(done==true){
            break;
        }

    }
}
void findturnaroundtime(int processes[],int burst_time[],int n,int wt[],int tat[]){
    for(int j=0;j<n;j++){
        tat[j]=burst_time[j]+wt[j];
    }
}