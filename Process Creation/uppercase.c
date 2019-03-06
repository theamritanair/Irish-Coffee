#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h>
#include<string.h>
#include<ctype.h>
#define READ 0
#define WRITE 1
int main(){

	pid_t p;

	char input_str[100];
	int fd[2];

	if (pipe(fd) == -1) {
	fprintf(stderr,"Pipe failed");
	return 1;
	}
	p = fork();
	
	if(p<0){
		printf(stderr, "Fork failed");
		return 1;
	}else if(p==0){

		printf("\n CHILD PROCESS \n");
		
		printf("Enter a string");
		scanf("%s", input_str);
	
		close(fd[READ]);
		write(fd[WRITE], input_str, strlen(input_str)+1);
		close(fd[WRITE]);

		return 0;
	}else{
		
		wait(NULL);
		printf("\n PARENT PROCESS\n");
		

		char str[100];
		close(fd[WRITE]);
		read(fd[READ], str, 100);
		printf("The string %s \n", str);		
		for(int i=0;i<strlen(str);i++){
			str[i]-=32;		
		}
	
		printf("The uppercase string is %s", str);
		close(fd[READ]);

		return 0;
	}

}
