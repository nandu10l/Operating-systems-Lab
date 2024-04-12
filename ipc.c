#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
void main(){
	char buff[100];  
	key_t key =ftok(".",'s');
	printf("%d\n",key);  
	int shmid=shmget(2345, 1024, IPC_CREAT|0666);   
	printf("%d\n",shmid);
	char * shared_memory= shmat(shmid,NULL,0);
	printf("%p\n",shared_memory);
	printf("Enter some data to write to shared memory\n");  
	read(0,buff,100);  
	strcpy(shared_memory,buff); 
	printf("You wrote %s\n",(char*)shared_memory);
	                                                                                           

}



