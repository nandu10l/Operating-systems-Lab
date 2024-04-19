#include<stdio.h>
void main(){

	int limit;
	printf("Enter the no. of process :");
	scanf("%d",&limit);
	
	int process[limit];
	
	struct memory{
		int size;
		int flag;
	}m[limit];
	
	printf("Enter the memory used by Processes:\n");
	for(int i=0;i<limit;i++){
		scanf("%d",&process[i]);
	}
	
	printf("Enter the size of memory slots available:\n");
	for(int i=0;i<limit;i++){
		scanf("%d",&m[i].size);
		m[i].flag=0;
	}
	
	for(int i=0;i<limit;i++){
		for(int j=0;j<limit;j++){
			if(process[i]<=m[j].size){
				if(m[j].flag==1){
					continue;
				}
				else{
					printf("Process %d is allocated to memory %d\n",i+1,m[j].size);
					m[j].flag=1;
					break;
				}
			}
		}
	}
}
