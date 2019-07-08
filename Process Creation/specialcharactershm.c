#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<ctype.h>


int main(){

	int shmid, status;
	int *c;	
	shmid = shmget(IPC_PRIVATE, sizeof(int) , IPC_CREAT|0666);

	pid_t pid;
	pid = fork();
	
	if(pid<0){
	printf(stderr, "fork failed");
	}else if (pid ==0){

		printf("CHILD PROCESSS \n");
		c = shmat(shmid,0,0);
		int i=1;
		char s[1024];
		printf("Enter a number \n");
		while(1){
			
			scanf("%s",&s);
			int n = atoi(s);
			if(isdigit(s[0])){
				*(c+i) = n;
				i++;
			}else{
				*c=i;	
				break;	
			}
		}
	}else{
	wait(NULL);
	printf("PARENt PROCESSS \n");
	
	c =shmat(shmid,0,0);
	int sum =0;	
	printf("%d",c[0]);
	for(int i=1;i<c[0];i++){
	sum = sum +c[i];
	}
	printf("The sum is %d \n ", sum);


	}
	return 0;

}
