#include<stdio.h>
#include<unistd.h>
void main(){
	int pd;
	pd=fork();
	if(pd==0){
		printf("Child process is running \n");
		printf("Process id is %d\n",getpid());
		printf("Parent id is %d\n",getppid());
		int lim;
		printf("Enter a limit :");
		scanf("%d",&lim);
		for(int i=0;i<=lim;i++){
			printf("%d\n",i);
		}
	}
	else if(pd>0){
		wait();
		printf("This is parent process\n");
		printf("Parent process id is %d\n",getppid());
		int num;
		printf("Enter a number :");
		scanf("%d",&num);
		if(num%2==0){
			printf("Number is even\n");
		}
		else {
			printf("Number is odd\n");
		}
	}
	else{
		printf("Fork failed");
	}
}
