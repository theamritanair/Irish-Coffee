#include <stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<ctype.h>

int main(){

	int shmid, status;
	char *a;
	char s[100];
	shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT|0666);

	if(fork() == 0){

	printf("CHILD PROCESS \n");
	a = (char *) shmat(shmid,0,0);
	printf("Enter a string \n");
	scanf("%s", a);
	
	

	//shmdt(a);
	
	
	}else{
	
	sleep(5);
	printf("PARENT PROCESS \n ");

	a = (char *) shmat(shmid, 0, 0);
	for(int i=0;i<strlen(a);i++){
		a[i]-=32;	
	}
	
	printf("The uppercase string is %s", a);
	
	//shmdt(a);
	//shmctl(shmid, IPC_RMID, 0);	
		
	}
	return 0;
}
	
	
	
	
	

