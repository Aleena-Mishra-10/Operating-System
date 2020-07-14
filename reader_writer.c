#include<stdio.h>
int wait(int);
int signal(int);
void writer();
void reader();
int wrt=1,mutex=1;//semaphore
int readCount=0;
int main(){
    int n;
    printf("1.Reader\n2.Writer\n3.Exit");
    while(1){
        printf("\nEnter your choice");
        scanf("%d",&n);
        switch(n){
            case 1 : if(wrt==1){
                        writer();
                    }else{
                        printf("Writer can't go inside");
                    }
                    break;
            case 2 : if(mutex==1){
                        reader();
                    }
                    else{
                        printf("Reader can't go inside");
                    }
        }

    }

    return 0;
}