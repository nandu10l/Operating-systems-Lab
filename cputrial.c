#include<stdio.h>
void main(){
	int ch=1,lim,i;
	float tot_wt , tot_tat; 
	while(ch!=0){
		printf("1.FCFS  2.SJF  3.PRIORITY  4.ROUND ROBIN   0.EXIT\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		
		if(ch==1){
			printf("Enter the no. of process:");
			scanf("%d",&lim);
				
			int process[lim],bt[lim],tat[lim],wt[lim];
			printf("Enter the process no and burst time\n");
			for(i=0;i<lim;i++){
				scanf("%d %d",&process[i],&bt[i]);
			}
			wt[0]=0;
			tat[0]=bt[0];
	
			tot_wt = wt[0], tot_tat = tat[0];
	
			for(i=1;i<lim;i++){
				wt[i]=wt[i-1]+bt[i-1];
				tat[i]=tat[i-1]+bt[i];
				tot_wt+=wt[i];
				tot_tat+=tat[i];
			}
	
			printf("Process\tBT\tWT\tTAT\n");
			for(i=0;i<lim;i++){
				printf("%d\t%d\t%d\t%d\n",process[i],bt[i],wt[i],tat[i]);
			}
			printf("Total WT = %f\nTotal TAT = %f\n",tot_wt,tot_tat);
    			printf("Average WT = %.2f\nAverage TAT = %.2f\n", tot_wt / lim, tot_tat / lim);
    			printf("\n");
    			for(i=0;i<lim;i++)
				printf("\t%d\t",process[i]);
			printf("\n");
			for(i=0;i<lim;i++)
				printf("%d\t\t",wt[i]);
			printf("%d",tat[lim-1]);
			printf("\n");
			printf("\n");
		}
		else if(ch==2){
			printf("Enter the no. of process:");
			scanf("%d",&lim);
				
			int process[lim],bt[lim],tat[lim],wt[lim];
			printf("Enter the process no and burst time\n");
			for(i=0;i<lim;i++){
				scanf("%d %d",&process[i],&bt[i]);
			}
			int j,temp;
    			for (i = 0; i < lim - 1; i++) {
        			for (j = i + 1; j < lim; j++) {
        			    if (bt[i] > bt[j]) {
                			temp = bt[i];
                			bt[i] = bt[j];
                			bt[j] = temp;
                
               				temp = process[i];
                			process[i] = process[j];
                			process[j] = temp;
            				}
        			}
    			}
    			wt[0] = 0; 
    			tat[0] = bt[0]; 
	
    			tot_wt = wt[0], tot_tat = tat[0];

    			for (i = 1; i < lim; i++) { 
        			wt[i] = wt[i - 1] + bt[i - 1];
        			tat[i] = tat[i - 1] + bt[i];
        			tot_wt += wt[i];
        			tot_tat += tat[i];
    			}

    			printf("Process\tBT\tWT\tTAT\n");
    			for (i = 0; i < lim; i++) {
       				printf("%d\t%d\t%d\t%d\n", process[i], bt[i], wt[i], tat[i]);
    			}
    			printf("Total WT = %f\nTotal TAT = %f\n",tot_wt,tot_tat);
    			printf("Average WT = %.2f\nAverage TAT = %.2f\n", tot_wt / lim, tot_tat / lim);
    			printf("\n");
    			for(i=0;i<lim;i++)
				printf("\t%d\t",process[i]);
			printf("\n");
			for(i=0;i<lim;i++)
				printf("%d\t\t",wt[i]);
			printf("%d",tat[lim-1]);
			printf("\n");
			printf("\n");	
		}
		else if(ch==3){
			printf("Enter number of process:\n");
    			scanf("%d", &lim);  
    			int process[lim], bt[lim], wt[lim], tat[lim],prio[lim], i; 
    			printf("Enter processes, burst time and corresponding priority:\n");
    			for (i = 0; i < lim; i++) {
        			scanf("%d%d%d", &process[i], &bt[i], &prio[i]);
    			}
    			int j,temp;
    			for (i = 0; i < lim - 1; i++) {
        			for (j = i + 1; j < lim; j++) {
         				if (prio[i] > prio[j]) {
            					temp=prio[i];
            					prio[i]=prio[j];
            					prio[j]=temp;
            	
                				temp = bt[i];
                				bt[i] = bt[j];
                				bt[j] = temp;
                
                				temp = process[i];
                				process[i] = process[j];
                				process[j] = temp;
            				}
        			}
    			}
     			wt[0] = 0; 
    			tat[0] = bt[0]; 

    			float tot_wt = wt[0], tot_tat = tat[0]; 
    
    			for (i = 1; i < lim; i++) { 
        			wt[i] = wt[i - 1] + bt[i - 1];
        			tat[i] = tat[i - 1] + bt[i];
        			tot_wt += wt[i];
        			tot_tat += tat[i];
    			}
    
    			printf("Process\tBT\tWT\tTAT\tPRIORITY\n");
    			for (i = 0; i < lim; i++) {
        			printf("%d\t%d\t%d\t%d\t%d\n", process[i], bt[i], wt[i], tat[i],prio[i]);
    			}
    			printf("Total WT = %f\nTotal TAT = %f\n",tot_wt,tot_tat);
    			printf("Average WT = %.2f\nAverage TAT = %.2f\n", tot_wt / lim, tot_tat / lim);
    
    			printf("\n");
    			for(i=0;i<lim;i++)
				printf("\t%d\t",process[i]);
			printf("\n");
			for(i=0;i<lim;i++)
				printf("%d\t\t",wt[i]);
			printf("%d",tat[lim-1]);
			printf("\n");
			printf("\n");
		}
		else if(ch==4){
			printf("Enter number of process:");
    	int lim,tq;
    	scanf("%d", &lim);
    	printf("Enter the time quantum:");
    	scanf("%d",&tq);  
    	int process[lim], bt[lim], wt[lim], tat[lim],balance_bt[lim], i;
    	int time=0,completed=0;
    	printf("Enter the process no and burst time\n");
	for(i=0;i<lim;i++){
		scanf("%d %d",&process[i],&bt[i]);
		balance_bt[i]=bt[i];
	}
	int Time_arr[10],P[10];
	int a=0;
    	while(completed<lim){
    		for(int i=0;i<lim;i++){
    			if(balance_bt[i]>0){
    				if(balance_bt[i]>tq){
    					time+=tq;
    					balance_bt[i]-=tq;
    					Time_arr[a]=tq;
    					P[a]=process[i];
    					a++;
    					
    				}
    				else{
    					time+=balance_bt[i];
    					wt[i]=time-bt[i];
    					tat[i]=time;
    					Time_arr[a]=balance_bt[i];
    					balance_bt[i]=0;
    					completed++;
    					P[a]=process[i];
    					a++;
    					
    				}
    			}
    		}
    	}
    	
    	float tot_wt = 0, tot_tat = 0; 
    	for(i=1;i<lim;i++){
				
		tot_wt+=wt[i];
		tot_tat+=tat[i];
	}
    	printf("Process\tBT\tWT\tTAT\n");
	for(i=0;i<lim;i++){
		printf("%d\t%d\t%d\t%d\n",process[i],bt[i],wt[i],tat[i]);
	}
	printf("Total WT = %f\nTotal TAT = %f\n",tot_wt,tot_tat);
    	printf("Average WT = %.2f\nAverage TAT = %.2f\n", tot_wt / lim, tot_tat / lim);
    	printf("\n");
    	
    	printf("GANTT CHART:\n");
    	
    	for(i=0;i<a;i++){
    		printf("   %d   ",P[i]);
    	}
    	printf("\n");
    	int y=0;
    	printf("%d   ",y);
    	for(i=0;i<a;i++){
    		printf("  %d   ",y+=Time_arr[i]);
    	}
    	
	printf("\n");
	printf("\n"); 
		}
		else{
			printf("Invalid option!");
		}
	}
}
