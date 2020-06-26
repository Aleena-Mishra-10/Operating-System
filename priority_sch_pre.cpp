#include<iostream>
using namespace std;
struct Process{
    int pid;
    int art,bt,priority,wt,tat;
    int status;

}process_queue[10];
 void arrival_time_sorting(int n);
 void find_average_time(int n,int burst_time);
int main(){
     int n , burst_time=0;
     cout<<"enter no of processes";
     cin>>n;
     cout<<"enter processID , arrival time , burst time , priority ";
     for(int j=0;j<n;j++)
     {
         cin>>process_queue[j].pid;
         cin>>process_queue[j].art;
         cin>>process_queue[j].bt;
         cin>>process_queue[j].priority;
         process_queue[j].status=0;
         burst_time=burst_time+process_queue[j].bt;
     }
    arrival_time_sorting(n);
    find_average_time(n,burst_time);
    return 0;
}
void arrival_time_sorting(int n){
    struct Process temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(process_queue[i].art>process_queue[j].art){
                temp=process_queue[i];
                process_queue[i]=process_queue[j];
                process_queue[j]=temp;
            }
        }
    }
}
void find_average_time(int n,int burst_time){
    process_queue[9].priority=-9999;
    int time=0,largest,completion_time;
    int total_wt=0,total_tat=0;
    cout<<"Process"<<"\t\t"
		<<"Burst Time"<<"\t\t"
        <<"Priority"<<"\t\t"
		<<"Waiting Time"<<"\t\t"
		<<"Turn Around Time"<<endl;
    for(time=process_queue[0].art;time<=burst_time;){
        largest=9;
        for(int i=0;i<n;i++){
            if(process_queue[i].art<=time&&process_queue[i].status!=1&&process_queue[i].priority>process_queue[largest].priority){
                largest=i;
            }
            time=time+process_queue[largest].bt;
            completion_time=time;
            process_queue[largest].wt=completion_time-process_queue[largest].bt-process_queue[largest].art;
            process_queue[largest].tat=process_queue[largest].wt+process_queue[largest].bt;
            process_queue[largest].status=1;
            total_wt=total_wt+process_queue[largest].wt;
            total_tat=total_tat+process_queue[largest].tat;
            cout<<"\n "<<process_queue[largest].pid<<"\t\t"<<process_queue[largest].bt<<"\t\t\t"<<process_queue[largest].priority<<"\t\t\t"<<process_queue[largest].wt<<"\t\t\t"<<process_queue[largest].tat<<endl;
        }
    }
    cout<<"\naverage waiting time="<<float(total_wt)/float(n);
	cout<<"\naverage turnaround time"<<float(total_tat)/float(n);

}