#include<stdio.h>
void main(){
	int limit,tq;
	printf("Enter the number of Process :");
	scanf("%d",&limit);
	
	printf("Enter the time quantum :");
	scanf("%d",&tq);
	int process[limit], bt[limit], wt[limit], tat[limit],balance_bt[limit], i, j, temp;
	printf("Enter the process and burst time:\n");
	
        for (i = 0; i < limit; i++) {
        	scanf("%d%d", &process[i], &bt[i]);
        	balance_bt[i]= bt[i];
        }
        
        int t=0;
        float tot_wt=0,tot_tat=0;
        while(1){
        	int done=1;
        	for(i=0;i<limit;i++){
        		if(balance_bt[i]>0){
        			done=0;
        			if(balance_bt[i]>tq){
        				t+=tq;
        				balance_bt[i]-=tq;
        			}
        			else{
        				t+=balance_bt[i];
        				wt[i]=t-bt[i];
        				balance_bt[i]=0;
        			}
        		}
        	}
        	if(done==1)
        		break;
        	}
        for(i=0;i<limit;i++){
        	tat[i]=bt[i]+wt[i];
        	tot_wt += wt[i];
        	tot_tat += tat[i];
        }
        printf("Process\tBT\tWT\tTAT\n");
   	for (i = 0; i < limit; i++) {
        	printf("%d\t%d\t%d\t%d\n", process[i], bt[i], wt[i], tat[i]);
    	}
    	
    	printf("Average WT = %.2f\nAverage TAT = %.2f\n", tot_wt / limit, tot_tat / limit);
                	
}

