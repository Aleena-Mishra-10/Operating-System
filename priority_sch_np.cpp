//#include<iostream>
//#include<algorithm>
#include<bits/stdc++.h>  // This file includes all standard library. Sometimes in some coding contests, when we have to save time while solving, then using this header file is helpful.
using namespace std;
struct Process{
    int pid;
    int bt;
    int priority;
};
void priorityScheduling(Process proc[],int n);
bool comparison(Process a,Process b);
void findaverage(Process proc[],int n);
void findWaitingTime(Process proc[],int n ,int wt[]);
void findTurnAroundTime(Process proc[],int n,int wt[],int tat[]);

int main(){
    Process proc[] = {{1,10,2},{2,5,0},{3,8,1}};
    int n = 3;
    priorityScheduling(proc,n);
    return 0;
}
void priorityScheduling(Process proc[],int n){
    sort(proc,proc+n,comparison);
    cout<<"Order in which the processes gets executed";
    for(int i=0;i<n;i++){
        cout<<proc[i].pid<<endl;
    }
    findaverage(proc,n);
}
bool comparison(Process a,Process b){
    return(a.priority>b.priority);
}
void findaverage(Process proc[],int n){
    int wt[n],tat[n];
    int total_wt=0,total_tat=0;
    findWaitingTime(proc,n,wt);
    findTurnAroundTime(proc,n,wt,tat);
    cout<<"Process"<<"\t\t"
		<<"Burst Time"<<"\t\t"
        <<"Priority"<<"\t\t"
		<<"Waiting Time"<<"\t\t"
		<<"Turn Around Time"<<endl;

	for(int i=0;i<n;i++){
		total_wt= total_wt + wt[i];
		total_tat=total_tat+tat[i];
		cout<<"\n "<<proc[i].pid<<"\t\t"<<proc[i].bt<<"\t\t\t"<<proc[i].priority<<"\t\t\t"<<wt[i]<<"\t\t\t"<<tat[i]<<endl;
	}
	cout<<"\naverage waiting time="<<float(total_wt)/float(n);
	cout<<"\naverage turnaround time"<<float(total_tat)/float(n);
}

void findWaitingTime(Process proc[],int n,int wt[]){
    wt[0]= 0;
    for(int j=1;j<n;j++){
        wt[j]=proc[j-1].bt+wt[j-1];
    }
}
void findTurnAroundTime(Process proc[],int n,int wt[],int tat[]){
    for(int j=0;j<n;j++){
        tat[j]=proc[j].bt+wt[j];
    }
}

